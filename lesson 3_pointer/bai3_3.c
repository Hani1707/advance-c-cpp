#include <stdio.h>
#include <assert.h>

void tong(int a, int b){  
    printf("Tong %d va %d: %d\n", a, b, a + b);
}

void hieu(int a, int b){
    printf("Hieu %d va %d: %d\n", a, b, a - b);
}

void tich(int a, int b){
    printf("Tich %d va %d: %d\n", a, b, a * b);
}

void thuong(int a, int b){
    assert(b != 0);
    printf("Thuong %d va %d: %f\n", a, b, (double)a / b);
}
void tinhToan(void (*ptr)(int, int), int a, int b){
    printf("Thuc hien phep toan duoi:\n");
    ptr(a, b);
}

int main(int argc, char const *argv[])
{
    int a = 20;
    char c = 'H';
    double d = 20.5;

    void *ptr = &a;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri a: %d\n", *(int *)ptr);

    ptr = &c;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri c: %c\n", *(char *)ptr);

    ptr = &d;

    printf("Gia tri: %p\n", ptr);
    printf("Gia tri d: %f\n", *(double *)ptr);

    ptr = &tich;

    printf("Gia tri: %p\n", ptr);
    ((void(*)(int, int))ptr)(7, 7);

    return 0;
}

