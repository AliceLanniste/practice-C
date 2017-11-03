#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdlib.h>


const int Mincapacity = 16;

typedef struct ImplementArray
{
    int size;
    int capacity;
    int *data;
} NArray;

extern NArray* create(int);
extern void resize(NArray*,int);
extern void doubleSize(NArray *);
extern void halfSize(NArray *);
extern int size(NArray *);
extern void push(NArray *,int);
extern int pop(NArray *);
extern bool is_empty(NArray *);
extern void insert(NArray *,int,int);
extern void prepend(NArray *,int);
extern void delete(NArray *,int);
extern void Nremove(NArray *,int value);
extern int find(NArray *,int);
extern int providedCapacity(int);

#endif