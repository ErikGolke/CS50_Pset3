/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If user inputs no command line arguments, or more than 2,
    // prints error message and terminates program
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // command line arguments are stored as characters,
    // this line converts char to an int.
    int n = atoi(argv[1]);

    // If 2 arguments are given,
    // the second is used as a seed 
    // to generate a number
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    // if only one argument, use the current time
    // to seed the number generator
    {
        srand48((long int) time(NULL));
    }

    // print out randomly generated numbers
    // one line at a time, multiyplying the random number
    // by the LIMIT, and casting it as an int
    // to truncate it
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}