// pig.cpp
// Alexander Le, CISP 400
// 1/29/19

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

// Global Variables - none, they were 'highly discouraged with prejudice'.

// Function Prototype(s)
void HiyaPlayer();
// Specification A2 - Group Stats
int GroupieStats(int);
// Specification B3 - Alpha Menu
char AlphaMenu(char);
// Specification C3 - Numeric Menu
int NumericMenu(int);
// Specification C2 - Student Name
void PlayerNames(int);
// Specification A1 - Main Event Loop
void SuperPig(char);


int main()
{
    // Program Greeting
    HiyaPlayer();
    // Specification A1 - Main Event Loop
    char play = 'n';
    cout << "Ready to play? ( y/n ): ";
    cin >> play;
    cout << "=========================================\n";
    SuperPig(play);
    
    // srand(time(0));
    
    return 0;
}

// Program Greeting
void HiyaPlayer()
{
    
    time_t rawtime;
    time (&rawtime);
    struct tm * timeinfo;
    char buffer[80];
    timeinfo = localtime(&rawtime);
    
    /*
     time and daate formatting parameters sourced from: http://www.cplusplus.com/reference/ctime/strftime/
     */
    
    // Specification A3 - Current Date
    strftime(buffer,sizeof(buffer),"%A, the %d of %B %G \n  The current time is: %r",timeinfo);
    string str(buffer);
    // Program greeting
    cout << "Welcome to Pig, a game of random chance.\n=========================================\n" << "It is " << str;
    cout<<"\n=========================================\nRules are as follows:\n=========================================\n- Players take turns rolling a die.\n- The die determines how many points they get.\n- They each recieve points each turn based on their roll.\n- The first player with 100 grand points is the winner!\n- The active player can either choose to hold or roll.\n- If they roll a 1, they will loose their turn.\n- However, if they roll any number from 2 to 6,\n  they will earn points exactly this number.\n- Holding skips to the next player and adds your \n  current total to the your grand total.\n=========================================\n";
    
    
    /*
     What I learned about the ctime library
     and how everything that I used works:
     -
     
     
     
     
     */
    
}

void PlayerNames(int playerNumber)
// This will now just process names for pig
// players = number of players
{
    
    /*string playerNames[players];
     for (int i = 0; i <= players; i++){
     string name;
     cout << "Please enter player " << i <<"'s name: ";
     cin.ignore();
     getline(cin, name);
     playerNames[i] = getline(cin, name);
     cout << "Welcome " << name << "!\n";
     }
     */
    string name;
    cout << "Please enter player 1's name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Welcome " << name << "!\n";
    for(int i = 2; i <= playerNumber; i++)
    {
        cout << "Please enter player " << i << "'s name: ";
        getline(cin, name);
        cout << "Welcome " << name << "!\n";
    }
    cout << "=========================================\nGood luck players! \nYou'll *definitely* need it to win.\n=========================================\n";
}

// Specification C1 - Time Seed
// Specification C2 - Student Name  done
// Specification C3 - Numeric Menu
// Specification C4 - Bulletproof Menu

// Specification B1 - Track each turn
// - dynamic to keep track of resignations
// Specification B2 - Randomnize Start
// Specification C3 - REPLACED
// Specification B3 - Alpha Menu
// Specification B4 - Resign Option

// Specification A1 - Main Event Loop
// Specification A2 - Group Stats
// Specification A3 - Current Date


// Specification A1 - Main Event Loop
void SuperPig(char choice)
{
    int players{};
    string name{};
    int * playerScores = nullptr;
    int x = 1;
    
    if(choice == 'y'){
        cout << "Welcome to the game!\n";
        cout << "How many players are there? : ";
        cin >> players;
        cout << "=========================================\n";
        cout << "Welcome you lovely " << players << " people playing together!\n";
        PlayerNames(players);
        //playerScores = new int[players];
        //for(int i = 0; i <= players; i++){
        //  playerArray[i];
        //}
        // cout << "\033[2J\033[1;1H"; // Clear the screen
        // Specification C3 - Numeric Menu
        
        NumericMenu(players);
        
        /*
         char play = 'n';
         cout << "\nReady to play? ( y/n ): ";
         cin >> play;
         for(int i = 0; i <=1; i++){
         SuperPig(play); // Recursive use
         }
         */
    }
    else if(choice == 'n'){
        cout << "The program will now exit.";
        exit(0);
    }
    else if (choice != 'y' && choice != 'n'){
        cout << "Invalid input.\nPlease enter 'y' for yes, or 'n' for no. ";
        char play = 'n';
        cout << "\nReady to play? ( y/n ): ";
        cin >> play;
        for(int i = 0; i <=1; i++){
            SuperPig(play); // Recursive use
        }
    }
}

//char confirm = 'n';
// cout << "Ready to play? ( y/n ): ";
// cin >> confirm;

int NumericMenu(int x)
{
    // x = the number of players
    int choice{}, roll{}, playerGrandTotal{}, currentTotal{};
    if(x >=1){
        for(int i = 1; i <= x; i++){
            cout << "\n\nPlayer "<< i << ", it is your turn to play!\n" << "You may choose to either:\n"
            << setw(7)
            << "1. Roll\n"
            << setw(7)
            << "2. Hold\n"
            << setw(7)
            << "3. Resign\n"
            << setw(7)
            << "4. Quit\n";
            cin >> choice;
            if(choice == 1){
                cout << "You chose to roll!\n";
                srand(unsigned(time(0)));
                roll = rand() % 6 + 1;
                cout << "Your roll lands you a " << roll << ",\n";
                if(roll ==1){
                    cout << "As you roll a one, you have unfortunately earned no points.";
                }
                else if(roll >=2 && roll <=6){
                    cout << "Nice! Your roll landed you a " << roll
                    << "\nAs a result, you earn exatly " << roll
                    << " points.\nThis is added to your grand total.";
                }
            }
            else if(choice == 2){
                cout << "You have chosen to hold.\n"
                << "As a result, no action will be taken and "
                << "\nyour turn will be skipped.";
                // needs to take current player number to assign to x
                x = 3;
                for(int i = 1; i <= x; i++){
                    cout << "\n\nPlayer "<< i << ", it is your turn to play!\n";
                    
                    cout << "You may choose to either:\n" << setw(7) << "1. Roll\n" << setw(7)
                    << "2. Hold\n" << setw(7) << "3. Quit\n";
                }
            }
            else if(choice == 3){
                // Specification B4 - Resign Option
                cout << "The active player has chosen to resign.\n" << "As a result, they are no longer playing\nand their points are made void.";
                int remainingPlayers = x;
                int nextPlayer = x;
                // Count players here
                --x;
                remainingPlayers = x;
                cout << "\nNumber of remaining players is "
                << remainingPlayers;
                
                remainingPlayers = x;
                //cout << "\n" << x << "\n";
                if(x <= remainingPlayers){
                    if(remainingPlayers == 1){
                        cout << "\nAs no other players exist aside from yourself,\nCongratulations, you win the game!";
                        // Find way to put player name in this string.
                        exit(0);
                    }
                }
            }
            else if(choice == 4){
                cout << "The active player has spoken.\n"
                << "Pig will now quit!\n";
                exit(0);
            }
        }
    }
    return x;
}

// Specification C3 - REPLACED
// Specification B3 - Alpha Menu
char AlphaMenu(char choice)
{
    int roll{}, playerGrandTotal{}, currentTotal{};
    if(choice == 'A' || 'a' || 'B' || 'b' || 'C' || 'c'){
        for(int i = 1; i <= choice; i++){
            cout << "\n\nPlayer "<< i << ", it is your turn to play!\n"
            << "You may choose to either:\n"
            << setw(7)
            << "1. Roll\n"
            << setw(7)
            << "2. Hold\n"
            << setw(7)
            << "3. Quit\n";
            cin >> choice;
            if(choice ==  'A' || 'a'){
                cout << "You chose to roll!\n";
                srand(unsigned(time(0)));
                roll = rand() % 6 + 1;
                cout << "Your roll lands you a " << roll << ",\n";
                if(roll ==1){
                    cout << "As you roll a one, you have unfortunately earned no points.";
                }
                else if(roll >=2 && roll <=6){
                    cout << "Nice! Your roll landed you a " << roll
                    << "\nAs a result, you earn exatly " << roll
                    << " points.\nThis is added to your grand total.";
                }
            }
            else if(choice == 'B' || 'b'){
                cout << "You have chosen to hold.\n"
                << "As a result, no action will be taken and "
                << "\nyour turn will be skipped.";
                // needs to take current player number to assign to x
                choice = 3;
                for(int i = 1; i <= choice; i++){
                    cout << "\n\nPlayer "<< i << ", it is your turn to play!\n";
                    
                    cout << "You may choose to either:\n" << setw(7) << "1. Roll\n" << setw(7)
                    << "2. Hold\n" << setw(7) << "3. Quit\n";
                }
            }
            else if(choice == 'C' || 'c'){
                // Specification B4 - Resign Option
                cout << "The active player has chosen to resign.\n" << "As a result, they are no longer playing and their points are void.";
                int remainingPlayers{};
                cout << "\nNumber of remaining players: "
                << remainingPlayers;
                // x = x - 1;
                // remainingPlayers = x;
                //cout << "\n" << x << "\n";
                if(choice <= remainingPlayers){
                    if(remainingPlayers == 1){
                        cout << "\nAs no other players exist aside from yourself, by default, you win.";
                    }
                }
            }
            else if(choice == 'D' || 'd'){
                cout << "The active player has spoken.\n"
                << "Pig will now quit!\n";
                exit(0);
            }
        }
    }
    return 0;
}


