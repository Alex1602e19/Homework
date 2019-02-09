/**********************************************************************************************
 *  Le, Alexander / Kwan, Justin
 *  Student ID: 1632780 / 1626114
 *  CISP 360 - B204, 6:00-7:20 on Tuesday
 *  Assignment #8 - Lottery Winners Modification
 *  Program file name: hw8_LotteryWinnersModification.cpp
 
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

//function prototypes
void results(bool);
void sort(int[],int);
bool bin_search(int[],int,int); // binary search
int const SIZE = 10;

int main (){
                     // 0    1     2    3      4    5     6      7     8     9
    int win[SIZE] = {13579,79422,26792,33445,55555,62483,26971,77777,85647,93121};
    //win = the winning numbers
    int ticket; // user's tickets
    bool result;
    bool cont; // continue playing?
    
    sort(win,SIZE);
    
    do {
        cout << setprecision(5) << fixed;
        cout << "Please enter this week's 5-digit winning lottery number: ";
        cin >> ticket;
        while(ticket < 0 || ticket > 99999){
            cout << "Please enter this week's 5-digit winning lottery number: ";
            cin >> ticket;
        }
        result = bin_search(win,SIZE,ticket);
        results(result);
        cout << "Do you have another lottery number?\n";
        cout << "1 = yes , 0 = no\n";
        cin >> cont;
    }while (cont == 1);
    
    
    
    //  cout << "\nsorted: ";
    //  showArray(win, SIZE);
    
    system("pause");
    
    return 0;
}

void sort(int w[],int num){
    bool swap;
    int temp;
    do
    {
        swap = false;
        for (int i = 0; i < (num - 1); i++) {    // -1 because this compared to the next element
            if (w[i] > w[i + 1])
            {
                temp = w[i];
                w[i] = w[i + 1];
                w[i + 1] = temp;
                swap = true;
            }
        }
    } while (swap);
}

bool bin_search(int numbers[], int size, int tickets) {
    
    bool winner = 0;
    int first = size - (size-1);
    int middle;
    int last = size - 1;
    
    do{
        winner = false;
        
        middle = (first + last) / 2; // halves the array
        
        if (numbers[middle] == tickets)
            winner = true;
        else if (numbers[middle] > tickets)
            last = middle - 1;   // reorganizes and sorts array
        else
            first = middle + 1;
        
    }while (!winner && first <= last);
    
    return winner;
}

void results(bool r){
    if(r == true)
        cout << "You have a winning ticket.\n";
    else
        cout << "You did not win this week.\n";
}

