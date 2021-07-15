#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;
    do{
        height = get_int("Height of pyramid: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++){
        //spaces
        for (int j = height - 1; j > i; j--){
            printf(" ");
        }
        //hashes
        for (int j = 0; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
}
