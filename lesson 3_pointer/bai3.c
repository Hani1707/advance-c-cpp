#include <stdio.h>

int a = 20;

int *ptr = &a;

int main(int argc, char const *argv[]){
    printf("dia chi a: %p\n", &a);
    printf("gia tri ptr: %p\n", ptr);
    return 0;
}