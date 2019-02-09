/**************************************************
 *  Le, Alexander
 *  vectors101.cpp
 **************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<string> b) // This function prints out the vector elements
{
    for (unsigned int i = 0; i < b.size(); i++) // we need to use unsigned int for vectors
    {
        cout << b[i] << " | "; // this symbol is called a pipe
    }
    cout << "\n";
}

int main()
{
    // vector<DataType> nameOfVector, vectors resize automatically, saves memory - more efficient
    // but harder to search through.
    
    vector<string> v; // must be declared here, not able to be initialized like an array at declaration.
    
    // vector initialization
    
    cout << "The numbers in the vector are: " << endl;
    for(int i=0; i < v.size(); i++)
        cout << v[i] << " ";
    
    int input;
    vector<int> v;
    cout << "Enter your numbers to be evaluated: " << endl;
    cin >> input;
    v.push_back(input);
    write_vector(v);
    return 0;
    
    v.push_back("yes");
    v.push_back("I eat food");
    v.push_back("yummy");
    v.push_back("food");
    
    // Vector.pushback adds an element to the vector and resizeses it.
    // .. Vector.size() --> returns an unsigned int equal to the number of elements.
    // Here there are 4 elements
    
    cout << "There are " << v.size() << " elements in this vector.\n";
    

    cout << "Elements stored in this vector: ";

    printVector(v);
    // system("pause");
    return 0;
}



