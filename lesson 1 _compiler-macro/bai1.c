#include <stdio.h>


#define CREATE_FUNC(func, cmd)   \
void func(){                     \
    printf(cmd);                   \
    printf("\n");\
}

#define CREATE_VAR(name)\
int int_##name;\
double double_##name;\
char char_##name;

CREATE_FUNC(test1, "this is function test1");
CREATE_FUNC(test2, "this is function test2");

CREATE_VAR(test);
int main(){

    test1();
    test2();

    return 0;
}