#include <iostream>
#include <cstring> // Required for strlen and memcpy

// This file demonstrates the use case of move semantics
// -> lvalue/rvalue concept is essential to avoid unnecessary deep copies
// -> Without move semantics, temporary objects are copied when passed to functions or returned
// -> Move semantics allows transferring ownership of dynamically allocated resources, avoiding deep copies

using namespace std;

class String {
private:
    int m_size = 0;
    char* m_data = nullptr;

public:
    // Default constructor (e.g., String s;)
    String() = default;

    // Parameterized constructor (e.g., String s("Saurabh");)
    String(const char* string) {
        cout << "created string\n";
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    // Copy constructor (deep copy)
    String(const String& other) {
        cout << "copied string\n";
        m_size = other.m_size;
        m_data = new char[m_size]; // problem wit copy is that we have to create a new string head, using extra memory
        memcpy(m_data, other.m_data, m_size);
    }

    // Move constructor (transfers ownership)
    String(String&& other) noexcept {
        cout << "moved string\n";
        m_size = other.m_size;
        m_data = other.m_data;
        other.m_data = nullptr;
        other.m_size = 0;
    }

    void print() const {
        for (int i = 0; i < m_size; i++) {
            cout << m_data[i];
        }
        cout << endl;
    }

    ~String() {

        cout << "destroyed " << endl;
        delete[] m_data; // ❗ always use delete[] when memory was allocated with new[]
    }
};

class Entity {
private:
    String m_name;

public:
    // constructor overloaded for lvalue and rvalue
    Entity(String& name) // rvalue passed but name is lvalue
        : m_name(name) // string is passed as lvalue as a result copy constructor will be called 
    {}
    //output: 
    // created string
    // copied string
    // destroyed
    // Saurabh
    // destroyed

    Entity(String&& name) // rvalue passed but name is lvalue
    //move(name) is simlar to (String&& ) name;
    : m_name(move(name)) // name is passed as rvalue as result move constructor is called
    {}
    // created string        ← temp String("Saurabh")
    // moved string          ← move from temp to m_name
    // destroyed             ← temp1 goes out of scope, has nullptr
    // Saurabh               ← print from m_name
    // destroyed             ← m_name in entity gets destroyed

    void PrintName() {
        m_name.print();
    }
};

int main() {
    Entity entity(String("Saurabh")); // Calls move constructor
    entity.PrintName();
    return 0;
}
