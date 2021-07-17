#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Asking for input for number of places user would like cipher text to be
int main(int argc, string argv[]){

    if (argc != 2){
        printf("missing command-line argument\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++){
        if ((isdigit(argv[1][i])) == false)
        {
        printf("Usage: .ceasar Key\n");
        return 1;
        }
    }


    string code = get_string("Provide plaintext\n");

    // Converting string digit into Integer
    int k = atoi(argv[1]);

    // Main program initialization
    for (int i = 0, n = strlen(code); i < n; i++){

        if isupper(code[i]){
            code[i] = ((((code[i] - 65) + k) % 26) + 65);
        }
        else if islower(code[i]){
            code[i] = ((((code[i] - 97) + k) % 26) + 97);
        }
    }

    printf("ciphertext: %s\n", code);
    return 0;
}