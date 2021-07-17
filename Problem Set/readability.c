#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void result(int index);

// ARRAY
string RESULT[] = {"Grade 16+", "Before Grade 1"};

int main(void)
{
    // Get input from user
    string input = get_string("Text: ");

    // Variables
    int letter = 0;
    int word = 1;
    int sentence = 0;

    // Count number of sentence/s, word/s, and letter/s
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence++;
        }
        if (isalpha(input[i]))
        {
            letter++;
        }
        if (input[i] == ' ')
        {
            word++;
        }
    }

    //Average per word/s
    float averageLetterPerWord = (((float)letter / word) * 100.0);
    float averageSentencePerWord = (((float)sentence / word) * 100.0);

    // Coleman-Liau index
    int index = round(0.0588 * averageLetterPerWord - 0.296 * averageSentencePerWord - 15.8);

    // Print result
    result(index);
    return 0;
}

// Print result
void result(int index)
{
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
        return;
    }
    else if (index < 1)
    {
        printf("%s\n", RESULT[1]);
        return;
    }
    printf("%s\n", RESULT[0]);
    return;
}