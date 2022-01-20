#include "main.h"

int main(int argc, char *argv[])
{
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
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

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    characters = getline(&buffer, &bufsize, fp);

    fclose(fp);
    return (0);
}