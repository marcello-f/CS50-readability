#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //Get text from user
    string text = get_string("Text: ");
    
    float letters, words, sentences;
    letters = 0;
    words = 1;
    sentences = 0;

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        //count letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        
        //count words
        if (isblank(text[i]))
        {
            words++;
        }
        
        //count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    
    // printf("%d letter (s)\n", letters);
    // printf("%d word (s)\n", words);
    // printf("%d sentence (s)\n", sentences);
    
    //Coleman-Liau index
    float l = (100 * letters / words);
    float s = (100 * sentences / words);
    float index = 0.0588 * l - 0.296 * s - 15.8;
    
    // printf ("%f\n", l);
    // printf ("%f\n", s);
    // printf ("%d\n", index);
    
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }


}
