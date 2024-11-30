#include <stdio.h>
#include <assert.h>

void tong(int a, int b){
    printf("Tong %d va %d: %d\n", a, b, a+b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a-b);
}

int tich(int a, int b){
    return a*b;
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a/b);
}

int main(int argc, char const *argv[])
{
    void (*ptr)(int, int);

    

    int (*test)(int, int);

    test = &tich;

    printf("Tich: %d\n", test(7, 7));

    return 0;
}
