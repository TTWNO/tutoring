#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    T* stackArray;
    int stackSize;
    int top;
public:
    Stack(int);
    Stack();
    ~Stack();

    // stack operations
	void push(T);
	void pop(T&); // set the int& as the return value instead of returning the value; very common
	void peek(T&);
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    
    friend ostream& operator<<(ostream&, Stack);
};

template <class T>
Stack<T>::Stack()
{
    stackArray = new T[100];
    stackSize = 100;
    top = -1;
}
template <class T>
Stack<T>::Stack(int Size){
    stackArray = new T[Size];
    stackSize = Size;
    top = -1;
}
template <class T>
Stack<T>::~Stack(){
    delete[] stackArray;
}

template <class T>
void Stack<T>::push(T num){
    if (isFull())
        cout << "The stack is full!" << endl;
    else
    {
        top++;
        stackArray[top] = num;
    }
}
template <class T>
void Stack<T>::pop(T& num){
    if (isEmpty())
        cout << "Stack is empty!" << endl;
    else 
    {
        num = stackArray[top];
        top--;
    }
}
template <class T>
void Stack<T>::peek(T& num){
    if (isEmpty())
        cout << "The stack is empty!" << endl;
    else 
        num = stackArray[num];
}

template <class T>
bool Stack<T>::isEmpty() const{
    return top == -1;
}
template <class T>
bool Stack<T>::isFull() const{
    return top == stackSize - 1;
}
template <class T>
void Stack<T>::display() const{
    if (isEmpty())
        for (int i = top; i>= 0; i--)
            cout << stackAray[i]<< " ";
}
/* OVERLOADING THE PRINTING TO cout (<<) operator

To be able to write something like the following:
cout << myStack;
we can override the prototype:
ostream& operator<<(ostream&, Stack)

This basically says:
Whenever you are trying to print an Stack object,
let me do something to the stream (the print stream) before it continues.
In this case, we want to modify the print stream to include the Stack information before it continues to the next item to be appended to the stream.

Play around with this function to see how it works :)
*/
template <class T>
ostream& operator<<(ostream& stream, Stack<T> is){
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
    Stack<int> myStack(5); // 5 = capacity of stack
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

	Stack<string> names;
	names.push("bob");
	names.push("me");
	names.display();
	return 0;
}