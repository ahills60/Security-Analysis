/* This header file defines counters for defining cost */

#include <stdio.h>
#include <stdlib.h>

#ifndef __COUNTERS_H_
#define __COUNTERS_H_

#define ADD                 0
#define SUB                 1
#define MUL                 2
#define DIV                 3
#define SHI                 4
#define AND                 5
#define OR                  6
#define XOR                 7

#define MAX_COUNTERS        8

// Variable defines
unsigned int counters[MAX_COUNTERS];
char countNames[MAX_COUNTERS] = "+-*/<&|^";

// Prototypes
void initialiseCounters(void);
void printCounters(void);
void incrementADD(int);
void incrementSUB(int);
void incrementMUL(int);
void incrementDIV(int);
void incrementSHI(int);
void incrementAND(int);
void incrementOR(int);
void incrementXOR(int);


// Functions:

void initialiseCounters(void)
{
    int n;
    
    for (n = 0; n < MAX_COUNTERS; n++)
        counters[n] = 0;
}

void printCounters(void)
{
    int n;
    printf("\n\nCounter results:");
    printf("\n=================\n\n");
    for (n = 0; n < MAX_COUNTERS; n++)
        printf("%c: %u\n", countNames[n], counters[n]);
    printf("\n");
}

void incrementADD(int inc)
{
    counters[ADD] += inc;
}
    
void incrementSUB(int inc)
{
    counters[SUB] += inc;
}
    
void incrementMUL(int inc)
{
    counters[MUL] += inc;
}
    
void incrementDIV(int inc)
{
    counters[DIV] += inc;
}
    
void incrementSHI(int inc)
{
    counters[SHI] += inc;
}
    
void incrementAND(int inc)
{
    counters[AND] += inc;
}
    
void incrementOR(int inc)
{
    counters[OR] += inc;
}
    
void incrementXOR(int inc)
{
    counters[XOR] += inc;
}

#endif