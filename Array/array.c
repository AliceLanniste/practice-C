#include <stdlib.h>
#include <stdbool.h>

/*
*创建一个数组最小容纳为16
**/
NArray* create(int capacity)
{
    int trueCapacity = providedCapacity(capacity);
    NArray *arr = malloc(sizeof(NArray));
    arr -> size = 0;
    arr -> capacity = trueCapacity;
    arr -> data =(int *) malloc(sizeof(int));
    return arr;
}


void resize(NArray *ptr,int otherindex)
{
 if(ptr->size < otherindex)
 {
     if(ptr->size==ptr->capacity)
        doubleSize(ptr);
 }
 else if(ptr->size > otherindex) 
 {
    if(ptr->size == ptr->capacity / 4)
        halfSize(NArray *ptr);
 }
}

void doubleSize(NArray *ptr)
{
    int oldCapacity = ptr -> capacity;
    int newCapacity = 2 * oldCapacity;
    int *newdata = (int *) malloc(sizeof(int) * newCapacity);
    for(int i=0;i<arr->size;i++)
    {
        *(newdata+i)=*(data+i);
    }
    free(ptr ->data);
    ptr ->data = newdata;
    ptr->capacity = newCapacity;
}

void halfSize(NArray *ptr)
{
    int oldCapacity = ptr ->capacity;
    int newCapacity = ptr ->capacity / 2;
    if(newCapacity < Mincapacity)
    {
        newCapacity = Mincapacity;
    }

    if(newCapacity != oldCapacity)
    {
    int *newdata =(int *) malloc(sizeof(int) * newCapacity);

    
        for(int i=0;i<ptr->size;i++)
        {
            *(newdata+i) = *(data+i);
        }
     
    free(ptr->data);
    ptr->data = newdata;
    ptr->capacity = newCapacity;
    }
}

int size(NArray *ptr)
{
    return ptr->size;
}


void push(NArray *ptr，int item)
{
    resize(ptr,arr->size+1);
    *(ptr->data + ptr->size) = item;
    ++(ptr->size);
}

int pop(NArray *ptr)
{
    if(ptr->size==0)
        exit(EXIT_FAILURE);

    resize(ptr,ptr->size-1);
    int popValue = *(ptr->data+ptr->size);
    --(ptr->size);     
    return popValue;
}


bool is_empty(NArray *ptr)
{
    int empty = 0;
    if(ptr->size == 0)
    {
        empty = 1;
    }
    return empty;
}


int at(NArray *ptr,int index)
{
    if(index < 0 || index >arr->size)
    {    exit(EXIT_FAILURE); }
    
    return *(arr->data+index);   
}

int providedCapacity(int cap)
{
    int capacity = Mincapacity;
    if(cap < 1)
    {
        exit(EXIT_FAILURE);        
    }

    if(cap > Mincapacity / 2)
    {
        capacity = 2 * capacity;
    }
    return capacity;
}


