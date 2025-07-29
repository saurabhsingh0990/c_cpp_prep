

#include <iostream>
using namespace std;


class String {
    public:
        int size;
        char *data;
    
        String (): data(nullptr), size(0){}; /// default constructor

        String(const char* string){
            size = strlen(string);
            data = new char[size + 1];
            for (int i = 0 ; i < size; i++){
                data[i] = string[i];
            }
            data[size + 1] = '\0';
        }// paramterized constructor;

        String operator+(String obj){ // + operator overloading
            String res;
            res.size = this -> size + obj.size;
            res.data = new char[res.size];
            for (int i = 0; i < this->size; i++){
                // cout << this -> data[i];
                res.data[i] = this -> data[i];
            }
            for (int i = 0 ; i < obj.size; i++ ){
                // cout << obj.data[i];
                res.data[i + this -> size] = obj.data[ i];
            }
            res.data[res.size + 1] = '\0';
            return res;
        }// + operator overload
        String(const String& obj){ // copy constructor
            size = obj.size;
            data = new char[size];
            for (int i = 0 ; i < size; i++){
                data[i] = obj.data[i];
            }
            data[size + 1] = '\0';
        }
        bool operator==(String obj){
            if (size != obj.size) return false;
            for (int i = 0; i < size; i++){
                if (data[i] != obj.data[i]) return false;
            }
            return true;
        }   
        void operator=(const String& obj){
            
            size = obj.size;
            data = new char[size];
            for(int i = 0 ; i < size; i++){
                data[i] = obj.data[i]; 
            }
            data[size + 1] = '\0';
        }
        
        int length(){
            return size;
        }
        int strlen(const char* string){
            int i = 0; 
            while (string[i] != '\0'){
                i++;
            }
            return i ;
        }// strlen 
        ~String(){
            delete[] data;
            data = nullptr;
        }
};

void print(String obj){
            for (int i = 0 ; i < obj.size; i++){
                cout << obj.data[i];
            }
            cout << endl;
}// print 
int main(){
    String firstName("Saurabh"); // creating new string
    String lastName("Singh");
    String fullName;
    fullName  = firstName + lastName; // concatination
    cout << "+ operator used : ";
    print(fullName);
    String newName; // empty string defult constructor called 
    newName = fullName; // copy assignment;
    cout << "copy assignment used : ";
    print(newName);
    String newFirstName = firstName; // copy constructor
    cout << "copy constructor : ";
    print(newFirstName);
    cout << "string lenght : "<<fullName.length() << endl;
    bool compare = firstName == newFirstName;
    cout << compare;
    return 0;
}