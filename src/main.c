#include "main.h"

int main(int argc, char *argv[])
{
    
    FILE *fp;

    while(argc--)
    {
        if(argv[1] == NULL || argc > 1)
        {
            printf("USAGE: monty file\n");
            exit(EXIT_FAILURE);
        }
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return (0);
}