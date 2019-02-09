/**************************************************
 *  Le, Alexander / Kwan, Justin
 *  Student ID: 1632780 / 1626114
 *  CISP 360 - B204, 6:00-7:20 on Tuesday
 *  Assignment #7 - Largest/Smallest
***************************************************/
// Program file name: hw7_LargestSmallest.cpp
// Program discription: This program prompts the user to enter 10 integers
// in response, it displays the largest and smallest value entered.

#include <iostream>

using namespace std;

int main (){
    
    int value[10],largest,smallest;
    
    cout << "This program will ask you to enter ten values, \nit will then determine the largest and smallest \nof the values you entered.\n\n";
    
    for(int i = 0; i<10; i++)
    {
        cout << "Enter an integer value: ";
        cin >> value[i];
        cout << "\n";
    }
    
    largest = value[0];
    smallest = value[0];
    
    for(int i = 0; i<10; i++)
    {
        if (largest < value[i])
            largest = value[i];
        
    }
    
    for(int i = 0; i<10; i++)
    {
        if (smallest > value[i])
            smallest = value[i];
    }
    
    cout << "The largest value entered is " << largest << ".\n";
    cout << "The smallest value entered is " << smallest << ".\n";
    
    system("pause");
    
    
    return 0;
}
