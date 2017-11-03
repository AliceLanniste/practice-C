void test_initSize()
{
    NArray *ptr = create(2);
    int initsize = size(ptr);
    assert(initsize == 0);
    Free(ptr); 
}


void test_capacity()
{
    NArray *ptr = create(8);
    int cap = ptr -> capacity;
    assert(cap==16);
    NArray *ptr2 = create(9);
    int cap2 = ptr2-> capacity;
    assert(cap==32);
    assert(cap2==32);
    Free(ptr);
    Free(ptr2);
}