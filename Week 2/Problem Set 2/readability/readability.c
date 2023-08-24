#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//prototypes of our functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //prompt the user for text.
    string text= get_string("Text: ");

    //count letters.
    int letters = count_letters(text);

    //count words.
    int words = count_words(text);

    //count sentences.
    int sentences = count_sentences(text);

    //calculate average no. of letters and sentences per 100 words.
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;

    //Coleman-Liau formula for determining grade level.
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //conditioning the output.
    if(index < 1)
    {
        printf("Before Grade 1");
        printf("\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+");
        printf("\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}




/////////////////////////////////////////////////////////////////
int count_letters(string text)
{
    int letter = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}
/////////////////////////////////////////////////////////////////
int count_words(string text)
{
    int word = 1;
    for(int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}
/////////////////////////////////////////////////////////////////
int count_sentences(string text)
{
    int sentence = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
/////////////////////////////////////////////////////////////////



