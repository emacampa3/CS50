#include <stdio.h>
#include <cs50.h>

int main(void){

    //Prompts the user for population at start
    int start;
    do{
        start = get_int("Start size: ");
    }
    while (start < 9);

    //Prompts the user for population at the end
    int end;
    do{
        end = get_int("End size: ");
    }
    while (end <= start);

    //counter for years passed
    int years = 0;

    //Updating the population until we reach end_population = start_population
    do{
        start = start + (start / 3) - (start / 4);
        years++;
    }
    while (end > start);

    //Printing the number of years needed
    printf("Years: %i\n", years);

}
