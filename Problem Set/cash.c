#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void){

    float amount;
    do{
        amount = get_float("Change owed: ");
    }
    while (amount < 0);

    int dollars = round(amount * 100);
    int x = 0;

    while (dollars >= 25){
        dollars = dollars - 25;
        x++;
    }

    while (dollars >= 10){
        dollars = dollars - 10;
        x++;
    }

    while (dollars >= 5){
        dollars = dollars - 5;
        x++;
    }

    while (dollars >= 1){
        dollars = dollars - 1;
        x++;
    }

    printf("%i\n", x);
}