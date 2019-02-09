/************************************************************
 //  Le, Alexander / Kwan, Justin
 //  Student ID: 1632780 / 1626114
 //  CISP 360 - B204, 6:00-7:20 on Tuesday
 //  Assignment #6 - Future Value
 *************************************************************/
// Program file name: hw6_FutureValue.cpp
/* Program discription: The program prompts the user to enter an account’s present value, monthly
   interest rate, and the number of months that the money will be left in the account to accrue.
   The program then passes these values onto a function named futureValue() which then returns the
   future value of the account, after the specified number of months. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

double futureValue(int, double, int); // Prototype

int main (){
    
    int p, t;
    //p = Present Value
    //t = Months
    double i,f;
    //i = Interest Rate
    char choice;
    
    do {
        cout << "What is the present value of the account? ";
        cin >> p;
        
        cout << "Enter the account's monthly interest rate? ";
        cin >> i;
        
        cout << "Enter the number of months that money will be left in the account: ";
        cin >> t;
        
        f = futureValue(p,i,t);
        
        cout << setprecision(2) << fixed;
        cout << "The future value of the account is $" << f << endl;
        cout << "Want to try another set of values? (y = yes): ";
        cin >> choice;
        
    }while ( choice == 'y' || choice == 'Y');
    
    system("pause");
    
    return 0;
}


double futureValue(int a, double b, int c) // a = p, b = i, c = t
{
    double x, y, z;
    
    x = 1 + b;
    y = pow(x,c);
    z = a*y;
    return z;
}


/* F=P×(1+i)^t
 
 The terms in the formula are as follows:
 o F is the future value of the account after the specified time period, the variable f will hold this value.
 o P is the present value of the account, the variable p will hold this value.
 o i is the monthly interest rate.
 o t is the number of months. */
