
// these are some bacis string operation 
// implmenting string class with these opeartions in implementation file 
#include <string>
#include <iostream>
using namespace std;

int main(){
    string firstName = "saurabh"; // creating new string
    string lastName = "Singh";
    string fullName = firstName + lastName; // concatination
    string newName;
    newName = fullName; // copy assignment;
    string newFirstName = firstName; // copy constructor;
    cout << fullName.length() << endl;
    cout << fullName << endl;
    return 0;
}