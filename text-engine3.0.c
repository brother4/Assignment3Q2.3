#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "levenshtein.h"

#define WORD_LENGTH 50

int main(int argc, char *argv[])
{
    FILE *dictionary = NULL;
    char userWord[WORD_LENGTH];
    char compareWord[WORD_LENGTH];
    char minWord[WORD_LENGTH];
    char page;
    int minDistance;
    int currDistance;
    dictionary = fopen(argv[1], "r");
    printf("What word should I check? \n");
    fgets(userWord, WORD_LENGTH, stdin);
    //removing the newline character
    userWord[strlen(userWord) - 1] = '\0';
    minDistance = strlen(userWord)+1;

    while(fgets(compareWord, WORD_LENGTH, dictionary) != NULL)
    {
        currDistance = levenshtein(userWord, compareWord);
        if (currDistance < 5) 
        {
            if (currDistance < minDistance) 
            {
                minDistance = currDistance;
                strcpy(minWord, compareWord);
            }
            insert(compareWord);
        }
    }
    fclose(dictionary);
    printf("Did you mean... %s\n", minWord);
    printf("There are %d other similar words, would you like to see them (y/n)? ", size());

}