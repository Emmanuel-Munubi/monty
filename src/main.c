#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

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
        printf("Couldn't open file\n");
        return 1;
    }
    return (0);
}