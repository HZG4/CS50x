#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//prompt User at the run time.
int main(int argc, string argv[])
{
    //check if its arguement count is 2
    //check if argv[1] is a numeric digit.
    if (argc == 2 && isdigit(*argv[1]))
    {

        //convert string argv[] to int
        int k = atoi(argv[1]);

        //get plain text from user
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");

        //count each char in plaintext array
        for (int i = 0; i < strlen(plaintext); i++)
        {
            //check if its uppercase letter and proceed
            if (isupper(plaintext[i]))
            {
                //use formula to compute the encrypted text
                printf("%c", (((plaintext[i] -  'A') + k) % 26) + 'A');
            }

            //check if its a lowercase letter and proceed
            else if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 'a') + k) % 26) + 'a');
            }

            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }

    //proceed this path if input is incorrect.
    else
    {
        printf("Usage: ./caser key");
        printf("\n");
        return 1;
    }
}

