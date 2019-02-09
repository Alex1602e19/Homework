/**************************************************
 *  Le, Alexander / Kwan, Justin
 *  Student ID: 1632780 / 1626114
 *  CISP 360 - B204, 6:00-7:20 on Tuesday
 *  Assignment #7 - Driver License Exam
 *  Program file name: hw7_DriverLicenseExam.cpp
 **************************************************/
// Program discription: This program grades the written portion of a driver’s license exam.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int const SIZE = 20;
    int correct = 0, incorrect = 0;
    char choice[SIZE];
    // 0   1     2    3   4     5    6   7    8     9   10   11   12   13    14  15   16   17   18   19
    char answers[] = {'X', 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    // Questions:     1    2    3    4    5    6    7    8    9    10   11   12   13   13   15   16   17   18   19   20
    // 'X' is a place holder for the array following comparison to work, it is NOT a test question answer.
    
    // Prompt
    
    cout << "Please enter the student's answers for each of the questions.\n" << "Press Enter after typing each answer.\n"
    << "Please enter only A, B, C, or D for each question.\n";
    for (int x = 1; x <= 20; x++){
        cout << "Question " << x << ": ";
        choice[0] = 'X'; // matching place holder WILL NOT count towards grade.
        cin >> choice[x];
        while(choice[x] != 'A' && choice[x] != 'B' && choice[x] != 'C' && choice[x] != 'D'){ // Input validation.
            cout << "Please enter only A, B, C, or D for each question.\n";
            cout << "Note: The program only accepts capital letters.\n";
            cout << "Question " << x << ": ";
            cin >> choice[x];
        }
    }
    
    for (int i = 1; i < 20; i++)
    {
        if(answers[i] == choice[i])
        {
            correct = correct + 1;
        }
    }
    
    incorrect = 20 - correct;
    
    if (correct >= 15){        // This is a "C" grade of 75 %
        cout << "\nThe student passed the exam.\n";
    }
    else {
        cout << "\nThe student failed the exam.\n";
    }
    
    
    cout << "Correct answers: " << correct << endl;
    cout << "Incorrect answers: " << incorrect << endl;
    cout << endl;
    cout << "Questions that were answered incorrectly:\n";
    for (int i = 1; i<20; i++)
    {
        if(answers[i] != choice[i])
        {
            cout << i << endl;
        }
    }
    
    
    system("pause");
    return 0;
}

