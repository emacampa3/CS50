#include <stdio.h>
#include <cs50.h>

int main(void){
    //Prompts a user for start_population
    int start_population;
    do{
        start_population = get_int("Start size: ");
    }
    while (start_population < 9);

    //Prompts a user for end_population
    int end_population;
    do{
        end_population = get_int("End size: ");
    }
    while (end_population < start_population);

    //counter for years passed
    int years = 0;
    //Updating the population until we reach end_population = start_population
    while (end_population > start_population){
        start_population = start_population + (start_population / 3) - (start_population / 4);
        years++;
    }
    //Printing the number of years needed
    printf("The number is %i\n", years);
}
