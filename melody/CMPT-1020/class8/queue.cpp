#include <iostream>

using namespace std;
template <class T>
class Queue
{
private:
    T* queueArray;
    int capacity;
    int numItems;

public:
    Queue(int size){
        queueArray = new T[size];
        capacity = size;
        numItems = 0;
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
            queueArray[numItems] = e;
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
            e = queueArray[0];

            for (int i = 0; i < numItems - 1; ++i)
            {
                queueArray[i] = queueArray[i+1];
            }
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
        if (isEmpty())
        {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "These are the elements of the array: " << endl;
        for (int x = 0; x < numItems; ++x)
        {
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