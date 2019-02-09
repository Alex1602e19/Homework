#include <iostream>

using namespace std;

// Function prototype


bool bin_search(const int [], int, int);

// Constant for array size

const int SIZE = 10;


int main()
{
    // Array of numbers that are always played
    
    int ticket[SIZE] = { 17,  26, 21,  33, 55,  62, 77,  22, 85,  93 };
    
    // This variable will hold the winning number.

    int winNum;
    
    // Get this week's winning number.
    
    cout << "\nPlease enter this week’s 2-digit winning lottery number: ";
    
    cin  >> winNum;

    // Search for the winning number.
    
    if (bin_search(ticket, SIZE, winNum))
    {
        // If searchList returned true, then the player has a winning ticket.
        cout << "You have a winning ticket!\n";
    }
    
    
    else
        
        
    {
        
        
        cout << "You did not win this week." << endl;
        
        
    }
    
    
    return 0;
    
    
}


// ********************************************************


// The searchList function accepts as arguments, an array *


// of numbers, the size of the array, and the number to   *


// search for. It determines if the number to search for  *


// is in the set of stored numbers using a binary search. *


// It returns true if the number is found, otherwise it   *


// returns false.                                         *


// ********************************************************


bool bin_search(const int list[], int listSize, int value)


{
    
    
    bool found = false;
    
    
    int first = 0;
    
    
    int middle;
    
    
    int last = listSize - 1;  //this is good
    
    
    while (!found && first <= last)  //this is good
        
        
    {
        
        
        middle = (first + last) / 2;
        
        if (list[middle] == value)
            
            
            found = true;
        
        
        else if (list[middle] > value)
            
            
            last = middle - 1;
        
        
        else
            
            
            first = middle + 1;
        
        
    }
    
    
    return found;
    
    
}


return -1;


}





//bubble sort algorithm to sort an array in ascending order.


#include <iostream>


using namespace std;


// Function prototypes


void bub_sort(int [], int);


void showArray(const int [], int);


int main()


{
    
    
    // Array of unsorted values
    
    
    int values[6] = {7, 2, 3, 8, 9, 1};
    
    
    // Display the values.
    
    
    cout << "The unsorted values are:\n";
    
    
    showArray(values, 6);
    
    
    // Sort the values.
    
    
    bub_sort(values, 6);
    
    
    // Display them again.
    
    
    cout << "The sorted values are:\n";
    
    
    showArray(values, 6);
    
    
    return 0;
    
    
}


//***********************************************************


// Definition of function sortArray                         *


// This function performs an ascending order bubble sort on *


// array. size is the number of elements in the array.     *


//***********************************************************


void bub_sort(int array[], int size)


{
    
    
    bool swap;
    
    
    int temp;
    
    
    do
        
        
    {
        
        
        swap = false;
        
        
        for (int i = 0; i < (size - 1); i++) {    // -1 because this compared to the next element
            
            
            if (array[i] > array[i + 1])
                
                
            {
                
                
                temp = array[i];
                
                
                array[i] = array[i + 1];
                
                
                array[i + 1] = temp;
                
                
                swap = true;
                
                
            }
            
            
        }
        
        
    } while (swap);
    
    
}


//*************************************************************


// Definition of function showArray.                          *


// This function displays the contents of array. size is the *


// number of elements.                                        *


//*************************************************************


void showArray(const int array[], int size)


{
    
    
    for (int count = 0; count < size; count++)
        
        
        cout << array[count] << " ";
    
    
    cout << endl;
    
    
}





//Selection sort


#include<iostream>


using namespace std;


void sel_sort(int[], int);


void showArray(int[], int);


int main()


{
    
    
    int values[] = { 7, 2, 3, 8, 9, 1 };
    
    
    showArray(values, 6);
    
    
    sel_sort(values, 6);
    
    
    showArray(values, 6);
    
    
    //system("pause");
    
    
    return 0;
    
    
}


void sel_sort(int array[], int arraySize)


{
    
    
    int pos, min_pos, minValue;
    
    
    for (pos = 0; pos < (arraySize - 1); pos++) //if not -1 here then will be out of boundary in the inner for loop
        
        
    {
        
        
        min_pos = pos; //location of the min Value
        
        
        minValue = array[pos];
        
        
        for (int seek = pos + 1; seek < arraySize; seek++) //ok to +1 here because -1 before in teh outter loop
            
            
        {
            
            
            //searching for the min and record the value and location
            
            
            if (array[seek] < minValue)
                
                
            {
                
                
                minValue = array[seek];  // reassign the minValue if there is a (bigger) smaller one
                
                
                min_pos = seek;         // remmeber the location
                
                
            }
            
            
        }
        
        
        //swaping
        
        
        array[min_pos] = array[pos];  //assign the 1st value to where the minValue is located
        
        
        array[pos] = minValue;         //assign the minValue to where 1st location
        
        
        cout << "Selection Sort in Progress" << endl;
        
        
        showArray(array, arraySize);
        
        
    }
    
    
}


void showArray(int array[], int arraySize)    // function heading


{
    
    
    for (int i = 0; i<arraySize; i++)
        
        
        cout << array[i] << "  ";
    
    
    cout << endl;
    
    
}






