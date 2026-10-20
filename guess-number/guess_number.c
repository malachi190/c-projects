#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50
#define MAX_ATTEMPTS 7

int main(void)
{
    // Seed random number generator at program start
    srand(time(NULL));

    int secret_number = rand() % MAX + 1;
    int guessed_number;
    int attempts = 0;
    int score = 0;
    int won = 0;

    while (attempts < MAX_ATTEMPTS)
    {
        // Take in user input
        printf("Enter a number between 1 & %d: \n", MAX);
        int result = scanf("%d", &guessed_number);

        if (result == EOF)
            return 1;

        // check if input is a valid integer
        if (result != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            printf("Invalid input, enter a number\n");
            continue;
        }

        // check if guessed number is within range
        if (guessed_number < 1 || guessed_number > MAX)
        {   
            printf("Invalid input, outside range 1 to %d\n", MAX);
            continue;
        }

        attempts++;

        if (guessed_number > secret_number)
            printf("Too high!\n");
        else if (guessed_number < secret_number)
            printf("Too low!\n");
        else
        {
            won = 1;
            break;
        }
    }

    if (won)
    {
        score = (MAX_ATTEMPTS - attempts + 1) * 2;
        printf("You win!!! You scored %d points in this round. Attempts = %d\n", score, attempts);
    }
    else
    {
        printf("Out of attempts. The number was %d.\n", secret_number);
    }

    return 0;
}