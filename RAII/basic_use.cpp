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
            else cout << "ptr is pointing to null";
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
    cout << "value 1 : ";
    obj.print();
    cout << "it is stored at loaction" << obj.get() << endl;
}

int main(){
    Raii int1 (new int(7));
    print(int1);
    
    return 0;
}