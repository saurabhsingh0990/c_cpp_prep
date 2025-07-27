// RAII stands for Resources Acqisition Is Intialization 
// Smart pointers work on this concept  
// int his concept resource is tied with the object
// that means resource(say heap memory) is acqiured when object is made and release when object is destroyed
// why should we remove copy constructor and copy assigmnet operator ?

#include <iostream>


using namespace std;

template <typename T>
class Raii{
    private:
        T *ptr;

    public:
        Raii(T *data = nullptr): ptr(data){
            cout << "constuctor called" << endl;
            cout << "ptr is created and address is "<< get() << endl;
        }
        Raii(Raii& obj) = delete; // copy constructor deleted
        Raii& operator= (Raii& obj) = delete; // copy assignment operator deleted 

        Raii(Raii&& obj){
            if (obj.ptr){
                this -> ptr =  obj.ptr;
                obj.ptr = nullptr;
            }
            else this -> ptr = nullptr;
        }

        Raii& operator= (Raii&& obj){
            if (obj.ptr){
                delete this -> ptr;
                this->ptr = obj.ptr;
                obj.ptr = nullptr;
            }
            else this -> ptr = nullptr;
            return *this;
        }
        T* get(){
            return ptr;
        }

        void print(){
            if (ptr)
                cout << *ptr << endl;
            else cout << "ptr is pointing to null"<< endl;
        }

        ~Raii() {
            cout << "destructor called" << endl;
            delete ptr; // resources (heap memory) cleared 
            ptr = nullptr; // avoid dangling pointer
            cout << "ptr now points towards null" << endl;
        }

};

template<typename T>
void print(Raii<T>& obj){
    cout << "value : ";
    obj.print();
    cout << "it is stored at loaction" << obj.get() << endl;
}

int main(){
    Raii<int> int1 (new int(7));
    cout << "int1 ";
    print(int1);
    Raii<string> name (new string("saurabh"));
    print(name);

    Raii<int> int2;
    cout << "move assignment operator " << endl;
    int2 = move(int1); // move assignment operator 
    cout << "int2 ";
    print(int2);
    cout << "int1 ";
    print(int1);
    cout << "move constructor " << endl;
    Raii<int> int3 = move(int2); // move constructor 
    cout << "int3 ";
    print(int3);
    cout << "int2 ";
    print(int2);
    return 0;
}