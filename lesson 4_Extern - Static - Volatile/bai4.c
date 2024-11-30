#include <stdio.h>

extern int cout;    // External integer variable
extern void display();  // External function

int main(int argc, char const *argv[])
{
    display();
    cout = 50;
    printf("Test: %d\n", cout);
    display();
    return 0;
}
