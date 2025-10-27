#include <stdio.h>


void notifyUser(){
    printf("\n Hey your coffee is ready !");
}


void make_coffee(void (*callback)(void)){
    printf("\n Starting machine ");
    printf("\n brew complete");
    callback();
}

int main(){
    printf("making Espresso");
    make_coffee(notifyUser);
    return 0;
}