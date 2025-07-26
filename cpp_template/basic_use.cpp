#include <iostream>
using namespace std;

// ✅ Generic Vector class using templates
template <typename T>
class Vector {
private:
    int size;
    T* arr;

public:
    // Constructor
    Vector(int m) : size(m) {
        arr = new T[size];
    }

    // Destructor to manage memory
    ~Vector() {
        delete[] arr;
    }

    // Copy constructor (for safety)
    Vector(const Vector& other) {
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Dot product with another vector
    T dotProduct(const Vector& v) const {
        T result = 0;
        for (int i = 0; i < size; ++i) {
            result += arr[i] * v.arr[i];
        }
        return result;
    }

    // Set element at index
    void set(int index, T value) {
        if (index >= 0 && index < size)
            arr[index] = value;
    }

    // Print all elements (optional utility)
    void print() const {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ✅ Generic print function
template <typename T>
void print(const T& data) {
    cout << data << endl;
}

int main() {
    // Integer Vectors
    Vector<int> vec1(3);
    Vector<int> vec2(3);
    vec1.set(0, 1); vec1.set(1, 2); vec1.set(2, 3);
    vec2.set(0, 1); vec2.set(1, 2); vec2.set(2, 3);
    print(vec1.dotProduct(vec2));  // 1*1 + 2*2 + 3*3 = 14

    // Float Vectors
    Vector<float> vec3(3);
    Vector<float> vec4(3);
    vec3.set(0, 1.1f); vec3.set(1, 2.0f); vec3.set(2, 3.0f);
    vec4.set(0, 1.5f); vec4.set(1, 2.7f); vec4.set(2, 3.0f);
    print(vec3.dotProduct(vec4));  // Should work fine with float

    // Generic print function
    print("hello");
    print(42);
    print(3.14159);

    return 0;
}
