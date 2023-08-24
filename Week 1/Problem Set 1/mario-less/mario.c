#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, row;

    //declare height limit for program.
    printf("Enter Height of Triangle (1-8). \n");

    //prompt until user inputs integer from 1-8.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    printf("\n");

    //set row
    for (row = 0; row < height; row++)
    {

        //print space with following computation
        for (int i = 0; i < height  - row - 1; i++)
        {
            printf(" ");
        }

        //print hashe with following computation
        for (int j = 0; j <= row; j++)
        {
            printf("#");
        }

        //print new line when one row completes
        printf("\n");
    }
    return 0;
}