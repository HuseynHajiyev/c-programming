#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

extern int errno;

void frequencyCount(FILE * stream, int * arr)
{
    int ch;
    while((ch = fgetc(stream)) != EOF)
    {
        if(isalpha(ch))
        {
            ++arr[tolower(ch) - 'a'];
        }
    }
    return;
}

int highestIndex(int * arr)
{
    int valueIndex = 0;
    for(int i = 0; i < 25; ++i)
    {
        if(arr[i] < arr[i+1])
        {
            valueIndex = i + 1;
        }
    }
    return valueIndex;
}

int decypherKey(int * arr)
{
    int index = highestIndex(arr);
    int count = 0;
    int key;
    if (index >= ('e' - 'a')) key=index-('e'-'a') ;
    else key=(26-('e'-'a'))+ index; 
    return key;
}
int main(int argc, char ** argv)
{
    int alphArr[26] = {0};
    if(argc != 2)
    {
        fprintf(stderr,"Wrong Input format: Include 1 file name");
        return EXIT_FAILURE;
    }
    FILE * encrypFile = fopen(argv[1],"r");
    if(encrypFile == NULL)
    {
        perror("Failed to open file");
    }
    frequencyCount(encrypFile, alphArr);
    int key = decypherKey(alphArr);
    printf("%d\n", key);
    if(fclose(encrypFile) != 0)
    {
        perror("failed to close file");
    }  
}