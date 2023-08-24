#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins \n");
    }
    else
    {
        printf("Its a Tie     \n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;

    //Calculate strlen to decide reitration for counting scores.
    int n = strlen(word);
    for(int i = 0; i < n; i++)
    {
        //Check if the char in array is capital and return boolean.
        if(isupper(word[i]))
        {
            //Word[1] decimal value in ASCII - 65 and return element.
            score = score + POINTS[word[i] - 65];
        }

        //Check if the char in array is small and return boolean.
        else if(islower(word[i]))
        {
            //word[1] decimal value in ASCII - 65 and return element.
            score = score + POINTS[word[i] - 97];
        }

        //When i > n, reitration of for()loop stops.
    }

    //Returns score to compute_scores function.
    return score;
}

