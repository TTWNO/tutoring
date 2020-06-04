#include <iostream>

using namespace std;

// Queue's are First In First Out (FIFO) systems.
// Much like a grocery store line.
template <class T>
class Queue
{
private:
    T* queueArray; // T* = arbitrarily allocated array of Ts
    /*
     * Use front and back instead of moving all the items each time you nheed to pop
     * 
     * Imagine this scenario:
     * You have a Queue of length 5. You have 3 values in it: [5, 6, 3].
     * Your bottom would be set to 0, and the top set to 2.
     * Now you want to dequeue the zeroth element. So you pop 5.
     * Instead of moving 6 to index zero, and moving 3 to index 1, simply move the head to 1 so that when you go through your list next time it will start reading from memory location 1, instead of zero.
     * 
     * You can also make this wrap around by checking when the 
     */
    int top;
    int bottom;
    int capacity;
    int numItems;

public:
    Queue(int size){
        queueArray = new T[size];
        capacity = size;
        numItems = 0;
        top = -1;
        bottom = -1;
	}
	~Queue(){
		delete[] queueArray;
	}
	void enqueue(T e) // called push_back in standard library
    {
        if (isFull())
        {
            cout << "Array is full" << endl;
        }
        else
        {
            // % capacity = up to capacity-1, if it is equal to capacity, make 0
            bottom = (bottom + 1) % capacity;
            queueArray[bottom] = e;
            ++numItems;
        }
        
    }
    void dequque(T& e)// called pop_front in standard library
    {
        if (isEmpty())
        {
            cout << "Array is empty" << endl;
        }
        else
        {
            // add one to top up to capacity; if == capacity, make 0
            top = (top + 1) % capacity; 
            e = queueArray[top];
            --numItems;
        }
    }
    bool isEmpty() // called empty in standard library
    {
        return numItems == 0; // returns true if numItems == 0
    }
    bool isFull()
    {
        return numItems == capacity;
    }
    void display()
    {
        int index = top;
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "These are the elements of the array: " << endl;
        for (int x = 0; x < numItems; ++x)
        {
            index = (index + 1) % capacity;
            cout << "[" << x << "]" << ": " << queueArray[x] << endl;
        }
    }
};

int main()
{
    const int MAX_VALUES = 5;
    Queue<int> iQueue(MAX_VALUES);
    int cacheVar;
    iQueue.enqueue(5);
    iQueue.display();
    iQueue.enqueue(12);
    iQueue.display();
    iQueue.enqueue(8);
    iQueue.display();
    iQueue.enqueue(15);
    iQueue.display();
    iQueue.enqueue(17);
    iQueue.display();
    iQueue.enqueue(5);

    iQueue.dequque(cacheVar);
    iQueue.display();
    iQueue.dequque(cacheVar);
    iQueue.display();
    iQueue.enqueue(99);
    iQueue.display();


	Queue <string>name(3);
	name.enqueue("people");
	name.enqueue("someone");
	name.enqueue("me");
	name.display();

    return 0;
}