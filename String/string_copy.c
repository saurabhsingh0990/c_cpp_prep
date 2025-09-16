#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void str_copy(const char *src, char **dest){
    *dest = (char *) malloc(sizeof(char) * (strlen(src)));
    strcpy(*dest, src);

}

int main(){
    const char *name = "saurabh"; 
    char *copied_name = NULL;
    str_copy(name, &copied_name);
    printf ( "copied name : %s", copied_name);
    return 0;
}