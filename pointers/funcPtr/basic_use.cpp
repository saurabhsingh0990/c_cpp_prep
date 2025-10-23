// Online C compiler to run C program online 
#include <stdio.h> 
int add(int x, int y){ 
    return (x + y); 
} 

int substract(int x, int y){ 
    return x - y; 
} 

int multiply(int x, int y){ 
    return x * y; 
} 

void swap(int *x, int *y){ 
    int temp = *x; *x = *y; *y = temp; 
} 

void print(){ 
    printf("\n demo for function pointer"); 
} 
int main() { 
    // Write C code here 
    void (*print_ptr)() = print; print_ptr(); 
    int (*add_ptr)(int, int) = NULL;

    add_ptr = add; 
    printf("\n addtion done %d",add_ptr(5, 6)); 
    
    int x = 9, y = 7; 
    printf("\n before swap %d , %d", x, y); 
    void (*swap_ptr)(int *, int *) = swap; 
    swap_ptr(&x, &y); printf("\n after swap %d , %d", x, y); 
    
    printf("\n array of function pointer"); 
    int operation = 0; 
    const char* operations[] = {"add", "substract", "multiply"}; 
    int (*array_ptr[])(int, int) = {add, substract, multiply}; 
    printf("\n %s : %d",operations[operation], array_ptr[operation](5, 10)); 
    return 0; 
}