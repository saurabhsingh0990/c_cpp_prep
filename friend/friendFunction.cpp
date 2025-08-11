#include <iostream>
#include <string>
using namespace std;

// ======================
// 📚 NOTES ON FRIEND FUNCTION
// ======================
// 1. A friend function is NOT a member of the class, but it can access private and protected members.
// 2. Friendship must be explicitly declared inside the class.
// 3. Common use case: When an external function needs access to a class’s private data
//    without making that data public.
// 4. Friendship is given to specific functions, not all functions of another class.
// 5. It is not mutual: Declaring a friend function in ClassA doesn't make ClassB's functions friends automatically.

// ==================================
// Class: BankAccount
// ==================================
class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance)
        : accountHolder(name), balance(initialBalance) {}

    // Declare friend function
    friend void showAccountDetails(const BankAccount &acc);
};

// ==================================
// Friend Function (NOT a class method)
// ==================================
// This function has access to BankAccount's private members
void showAccountDetails(const BankAccount &acc) {
    cout << "Account Holder: " << acc.accountHolder << endl;
    cout << "Current Balance: $" << acc.balance << endl;
}

// ==================================
// Normal non-friend function (to show restriction)
// ==================================
void tryToAccess(const BankAccount &acc) {
    // ❌ This will cause a compile error if uncommented:
    // cout << acc.balance; // 'balance' is private
    cout << "Cannot access balance here because this is not a friend function." << endl;
}

// ==================================
// MAIN
// ==================================
int main() {
    BankAccount john("John Doe", 1500.75);

    cout << "--- Using Friend Function ---" << endl;
    showAccountDetails(john); // ✅ Works, can see private data

    cout << "--- Using Normal Function ---" << endl;
    tryToAccess(john); // ❌ Cannot see private data

    return 0;
}
