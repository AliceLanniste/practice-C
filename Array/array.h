#ifndef ARRAY_H
#define ARRAY_H


const int Mincapacity = 16;

typedef struct ImplementArray
{
    int size;
    int capacity;
    int *data;
} NArray;


extern int providedCapacity(int);

#endif