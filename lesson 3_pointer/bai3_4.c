#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    char c = 'A';
    double d = 10.3;
    void *ptr = &a;

    printf("Gia tri: %p\n", ptr);

    ptr = &c;

    printf("Gia tri: %p\n", ptr);

    ptr = &d;

    printf("Gia tri: %p\n", ptr);

    return 0;
}
