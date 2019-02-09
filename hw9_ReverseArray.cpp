/**************************************************
 *  Le, Alexander / Kwan, Justin
 *  Student ID: 1632780 / 1626114
 *  CISP 360 - B204, 6:00-7:20 on Tuesday
 *  Assignment #7 - Reverse Array
 *  Program file name: hw9_ReverseArray.cpp
 *  Program discription: This program copies and reverses an array using pointers
 **************************************************/
#include <iostream>

using namespace std;

const int SIZE = 10;

int* reverseArray(int [], int);

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << "The contents of the original array are:\n ";
    for (int i = 0; i < SIZE; i++)
        cout << array[i] << " ";

    cout << "\nThe contents of the copy are:\n ";
    int * copy = reverseArray(array, SIZE);
    for (int i = SIZE - 1; i >= 0; i--)
        cout << *(copy + i) << " ";
    cout << "\n\n---------------------------------------";

    system("read -n 1 -s -p \"\nPress any key to continue...\"");
    //system("pause");
    return 0;
}

int* reverseArray(int array[], int size)
{
    // make a copy of the array
    int arrayCopy[size];
    
    int *p = nullptr;
    p = array;
    int *b = nullptr;
    b = arrayCopy;
    int *a, *d;
    a = p;
    d = b;
    while (*a != '\0')
        *d++ = *a++;
    *d = '\0';
    
    int maxIndex, maxValue;
    
    for (int startScan = size-1; startScan >= 0; startScan--)
    {
        maxIndex = startScan;
        maxValue = p[startScan];
        for(int index = startScan; index > size; index--) //step through array
        {
            if (p[index] < maxValue)
            {
                maxValue = p[index];
                maxIndex = index;
            }
        }
        p[maxIndex] = array[startScan];
        p[startScan] = maxValue;
    }
    
    return p;
}
