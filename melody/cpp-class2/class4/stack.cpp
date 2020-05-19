#include <iostream>

using namespace std;

class IntStack
{
private:
    int* stackArray;
    int stackSize;
    int top;
public:
    IntStack(int);
    IntStack();
    ~IntStack();

    // stack operations
    void push(int);
    void pop(int&); // set the int& as the return value instead of returning the value; very common
    void peek(int&);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    
    friend ostream& operator<<(ostream&, IntStack);
};

IntStack::IntStack()
{
    stackArray = new int[100];
    stackSize = 100;
    top = -1;
}
IntStack::IntStack(int Size){
    stackArray = new int[Size];
    stackSize = Size;
    top = -1;
}
IntStack::~IntStack(){
    delete[] stackArray;
}

void IntStack::push(int num){
    if (isFull())
        cout << "The stack is full!" << endl;
    else
    {
        top++;
        stackArray[top] = num;
    }
}
void IntStack::pop(int& num){
    if (isEmpty())
        cout << "Stack is empty!" << endl;
    else 
    {
        num = stackArray[top];
        top--;
    }
}
void IntStack::peek(int& num){
    if (isEmpty())
        cout << "The stack is empty!" << endl;
    else 
        num = stackArray[num];
}

bool IntStack::isEmpty() const{
    return top == -1;
}
bool IntStack::isFull() const{
    return top == stackSize - 1;
}
void IntStack::display(){
if ()
	for (int i = top; i>= 0)
		cout << stackAray[i]<< " ";
}
/* OVERLOADING THE PRINTING TO cout (<<) operator

To be able to write something like the following:
cout << myStack;
we can override the prototype:
ostream& operator<<(ostream&, IntStack)

This basically says:
Whenever you are trying to print an IntStack object,
let me do something to the stream (the print stream) before it continues.
In this case, we want to modify the print stream to include the IntStack information before it continues to the next item to be appended to the stream.

Play around with this function to see how it works :)
*/
ostream& operator<<(ostream& stream, IntStack is){
    if (is.isEmpty()){
        stream << "[]" << endl;
    } else {
        for (int i = is.top; i >= 0; i--){
           stream << "[" << i << "]: " << is.stackArray[i] << endl; 
        }
    }
    return stream;
}

int main(){
    int catchVar;
    IntStack myStack(5);
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);
    myStack.push(25);
    myStack.display();

    cout << "Peeking" << endl;
    myStack.peek(catchVar);
    cout << "Peeking" << endl;
    myStack.peek(catchVar);

    cout << "Popping" << endl;
    myStack.pop(catchVar);
    cout << "Popping" << endl;
    myStack.pop(catchVar);
    cout << "Popping" << endl;
    myStack.pop(catchVar);
    cout << "Popping" << endl;
    myStack.pop(catchVar);
    cout << "Popping" << endl;
    myStack.pop(catchVar);
    cout << "Popping" << endl;
    myStack.pop(catchVar);


    return 0;
}