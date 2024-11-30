#include <stdio.h>

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3
}Pins;
typedef enum{
    LOW,
    HIGH
}Status;

#define STM32   0
#define PIC     1
#define ATMEGA  2

#define MCU ATMEGA

#if MCU == STM32
void digitalWrite(Pins pin, Status status){
    if(status == HIGH){
        GPIOA->BSRR |= (1<<pin);
    }else{
        GPIOA->BSRR |= ((1<<pin) <<16);
    }

}
#elif MCU == ATMEGA
 void digitalWrite(Pins pin, Status status){
    if(status == HIGH){
        //PORTB |= (1 << pin);
    }else{
        //PORTB &= ~(1 << pin);
    }
 }
#endif
int main(int argc, char const *argv[])
{
    while (1)
    {
        digitalWrite(PIN0, HIGH);
        //delay(500);
        digitalWrite(PIN0, LOW);
        //delay(500);
    }

    return 0;
}
