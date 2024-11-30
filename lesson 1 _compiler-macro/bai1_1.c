#include <stdio.h>

//#define DISPLAY(...)\
char *string = #__VA_ARGS__;

#define tong(...)\
int array[]= {__VA_ARGS__, -1};\
int i = 0;\
int sum = 0;\
while (array[i] != -1)\
{\
    sum = sum + array[i];\
    i++;\
}\
printf("tong =%d\n", sum);

int main(){
    tong(5, 6, 7, 9, 12);
    return 0;
}
