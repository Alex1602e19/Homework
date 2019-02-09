/**********************************************************************************************
 *  Le, Alexander / Kwan, Justin
 *  Student ID: 1632780 / 1626114
 *  CISP 360 - B204, 6:00-7:20 on Tuesday
 *  Assignment #8 - Lottery Winners
 *  Program file name: hw8_Lottery Winners.cpp
 
 *  Program discription: This rogram initializes an array or a vector
 with a week's predetermined 5-digit winning numbers.
 It then prompts the player to enter the week’s winning
 5-digit number.
 
 * The program performs a linear search through the list of the player’s numbers and reports
 whether or not one of the tickets is a winner for the week's lottery.
 *************************************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

void check(int[],int,int);
int const SIZE = 10;

int main (){
    // 0    1     2     3     4      5     6     7       8      9
    int win[SIZE] = {13579,26971,26792,33445,55555,62483,77777,79422,85647,93121};
    //win = the winning numbers
    int ticket; // user's tickets
    bool cont; // continue playing?
    
    do {
        cout << setprecision(5) << fixed;
        cout << "Please enter this week's 5-digit winning lottery number: ";
        cin >> ticket;
        while(ticket < 0 || ticket > 99999){
            cout << "Please enter this week's 5-digit winning lottery number: ";
            cin >> ticket;
        }
        check(win,SIZE,ticket);
        cout << "Do you have another lottery number?\n";
        cout << "1 = yes , 0 = no\n";
        cin >> cont;
    }while (cont == 1);
    
    system("pause");
    
    return 0;
}

void check(int w[],int num,int tic){
    bool result = 0;
    for(int i = 0; i < num;i++){
        if (w[i] == tic)
            result = 1;
    }
    if (result == 1)
        cout << "You have a winning ticket.\n";
    else
        cout << "You did not win this week.\n";
}
