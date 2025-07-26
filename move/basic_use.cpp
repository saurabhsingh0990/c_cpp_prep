#include <iostream>
#include <cstring> // For strlen and memcpy

//quick revision
//-------------------------------------------------------------------------------
/*
🔹 lvalue: Something that has a memory address (can appear on the left-hand side of =)
    e.g., int x = 10;      // x is lvalue
🔹 rvalue: Temporary object without a stable address (usually on right-hand side)
    e.g., 10, String("Hi") // literals, temporaries are rvalues

🔹 Why move semantics?
    - Avoid expensive deep copies when passing/returning temporary (rvalue) objects
    - Transfers resource ownership without duplication

🔹 Key points:
    - String(String&& other): Move constructor
    - String& operator=(String&& other): Move assignment
    - std::move() is REQUIRED to convert an lvalue to rvalue

🔹 Example:
    String str = "abc";        // constructor
    String str2 = std::move(str); // move constructor
*/

//-------------------------------------------------------------------------------
// ✅ This file demonstrates:
//  - Move semantics in C++
//  - Difference between lvalue and rvalue
//  - Use of move constructor and move assignment operator
//  - Why using std::move is important for rvalue references

using namespace std;

// 🟩 A simple String class that manages a dynamic char array
class String {
private:
    int m_size = 0;
    char* m_data = nullptr;

public:
    // ✅ Default constructor
    String() = default;

    // ✅ Parameterized constructor
    // Called when you do: String s("Hello");
    String(const char* string) {
        cout << "created string\n";
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size); // no null terminator intentionally
    }

    // ✅ Copy constructor (deep copy)
    String(const String& other) {
        cout << "copied string\n";
        m_size = other.m_size;
        m_data = new char[m_size]; // Deep copy
        memcpy(m_data, other.m_data, m_size);
    }

    // ✅ Move constructor (steals resource from other)
    String(String&& other) noexcept {
        cout << "moved string\n";
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_data = nullptr; // Leave 'other' in a safe, destructible state
        other.m_size = 0;
    }

    // ✅ Move assignment operator
    String& operator=(String&& other) noexcept {
        cout << "move assigned\n";
        if (this != &other) {
            delete[] m_data; // Free existing data if any
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_data = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    // ✅ Helper function to print the string
    void print() const {
        for (int i = 0; i < m_size; i++) {
            cout << m_data[i];
        }
        cout << endl;
    }

    // ✅ Destructor
    ~String() {
        cout << "destroyed\n";
        delete[] m_data;
    }
};

// 🟩 Entity class demonstrating how move semantics avoid unnecessary copies
class Entity {
private:
    String m_name;

public:
    // ✅ Constructor for lvalue (calls copy constructor of String)
    Entity(const String& name)
        : m_name(name) {
        // Here, 'name' is an lvalue, so copy constructor is called
    }

    // ✅ Constructor for rvalue (calls move constructor of String)
    Entity(String&& name)
        : m_name(std::move(name)) {
        // Important: without std::move(name), it would call copy constructor
        // because 'name' is an lvalue (even if it is of type String&&)
    }

    void PrintName() const {
        m_name.print();
    }
};

int main() {
    // 🧪 Test Case 1: Entity initialized with temporary String (rvalue)
    {
        cout << "Entity Scope started\n";
        Entity entity(String("Saurabh")); // rvalue: move constructor is called
        entity.PrintName();
        cout << "Entity Scope ended\n\n";
    }

    // 🧪 Test Case 2: Direct usage of move constructor and move assignment
    {
        cout << "Direct Move Scope started\n";

        String str = "Singh";           // Created
        String dest = std::move(str);   // Moved (constructor)
        cout << "dest used move constructor: ";
        dest.print();

        String dest_assigned;
        dest_assigned = std::move(dest); // Moved (assignment)
        cout << "dest_assigned used move assignment: ";
        dest_assigned.print();

        cout << "Direct Move Scope ended\n";
    }

    return 0;
}
