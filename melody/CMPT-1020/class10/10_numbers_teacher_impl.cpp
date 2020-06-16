/* TEACHER's CODE */
#include <iostream>
using namespace std;

int linearSearch(double[], int, double);

int main()
{
    double key, list[10] = {-5, 25, 78, 121};
    int index;

    /*
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter a number: ";
        cin >> list[i];
    }*/
    cout << "Enter the number you are looking for: ";
    cin >> key;

    index = linearSearch(list, 10, key);
    if (index == -1)
        cout << "Not found!\n";
    else
        cout << "The number you are looking for is located at position: " << index + 1 << endl; 
}

int binarySearch(double L[], int size, double K)
{
    
}

// Big O Notation: O(n^2)
void selectionSort(double list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        double currentMin = list[i];
        int currentMinIndex = i;

        for (int j = i + 1; j < listSize; j++)
        {
            if (currentMin > list[j])
            {
                currentMin = list[j];
                currentMinIndex = j;
            }
        }
        if (currentMinIndex != i)
        {
            list[currentMinIndex] = list[i];
            list[i] = currentMin;
        }
    }
}

int linearSearch(double L[], int size, double K)
{
    for (int i = 0; i < size; i++)
    {
        if (L[i] == K)
            return i;
    }
    return -1;
}

// Big O Notation: O(n^2)
void insertSort(int list[], int listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        // insert list[i] into a sorted sublist list[0..i-1] so that
        //  list[0..i] is sorted
        int currentElement = list[i];
        int k;
        for (k = i - 1; k >= 0 && list[k] > currentElement; k--)
        {
            list[k + 1] = list[k];
        }
        // insert current element into list
        list[k + 1] = currentElement;
    }
}

int search(double L[], int size; double K){
    int low=0, high=size, mid;
    while (high>=low){
        mid=(low+high)/2;
        if (k<l)
            high=mid-1;
        else if (k==l[m])
            return mid;
        else
            low=+mid;
    }
}

