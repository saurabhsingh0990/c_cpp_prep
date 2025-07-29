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
    cout << fullName.length();
    cout << fullName;
    return 0;
}