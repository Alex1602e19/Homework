/* *****************************************************
 * Le, Alexander / Kwan, Justin
 * Student ID: 1632780 / 1626114
 * CISP 360 - B204, 6:00-7:20 on Tuesday
 * Assignment #9 - Pointer Rewrite
 * Program file name: hw9_Pointer Rewrite.cpp
 * Program description: This program reimplenments the
 *                      doSomething() function with pointers
 *                      and uses it in a complete program
 *                      with calls to the function.
 *******************************************************/

#include <iostream>
#include <string>

using namespace std;

int doSomething(int *, int *);
// function prototype
void prompt(int);

int main() // definition of main
{
    int firstvalue, secondvalue, input;
    int * pointer1 = nullptr;
    int * pointer2 = nullptr;
    
    pointer1 = &firstvalue; // This pointer takes the address of firstvalue
    pointer2 = &secondvalue; // This pointer takes the address of secondvalue
    
    prompt(1);
    cout << "Please enter an integer number: ";
    cin >> input;
    firstvalue = input;
    cout << "\tThis value will now be multiplied by 10";
    
    cout << "\nPlease enter a second integer number: ";
    cin >> input;
    secondvalue = input;
    cout << "\tThis value will now be multiplied by 10\t";
    
    cout << "\nThe unique sum of these values is " << doSomething(pointer1, pointer2) << endl;
    //cout << "firstvalue is " << firstvalue << '\n';
    //cout << "secondvalue is " << secondvalue << '\n';
    return 0;
}

int doSomething(int *x, int *y)
{
    int temp = *x;
    *x = *y*10;
    *y = temp*10;
    return *x + *y;
}

void prompt(int a)
{
    string header = "\n--------------------------------------------------\n";
    if(a ==1){
        cout << "Adding by 10 game " << header << "You will enter two seperate integers that will\n"
        << "each be multiplied by 10, then the program will \nswap the numbers and add to give you a unique\nsum from our game that you share with friends!" << header << "Are you ready? Let's play!" << header;
    }
}


/* *--*-------**--------------**-------******-------**-------******-------***-------***-----=+
 |      Oo                                                                                    |
 |     o  O               o                                                          .oOOo.   |
 |    O    o                                                      O           o  o   O    o   |
 |   oOooOoOo                                                    oOo        ooOooOoo o    O   |
 |   o      O .oOo  .oOo  O  .oOoO 'OoOo. `oOOoOO. .oOo. 'OoOo.   o           O  O   `OooOo   |
 |   O      o `Ooo. `Ooo. o  o   O  o   O  O  o  o OooO'  o   O   O         ooOooOoo      O   |
 |   o      O     O     O O  O   o  O   o  o  O  O O      O   o   o           O  O        o   |
 |   O.     O `OoO' `OoO' o' `OoOo  o   O  O  o  o `OoO'  o   O   `oO                `OooO'   |
 |                               O                                                            |
 |                           OoO'                                                             |
 |                                                                                            |
 |                   O           O                                                            |
 |                              oOo                                                           |
 |      .oOo. .oOo. O  'OoOo.   o   .oOo. `OoOo. .oOo            ASCII ART IS FUN             |
 |      O   o O   o o   o   O   O   OooO'  o     `Ooo.                                        |
 |      o   O o   O O   O   o   o   O      O         O                                        |
 |      oOoO' `OoO' o'  o   O   `oO `OoO'  o     `OoO'                                        |
 |      O                                                                                     |
 |      o'                                                                                    |
 * - * - * _ * - - * _ * -- * _ * -- * _ * -- * _ * -- * _ * -- * _ * -- * _ * -- * _ * - *-=*/




