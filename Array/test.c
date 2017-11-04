void all_test()
{
    test_initSize();
    test_capacity();
    test_append();
    test_resize();
    test_empty();
    test_at();
    test_insert();
    test_prepend();
    test_pop();
    test_remove();
    test_find();
}



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

/*test push*/
void test_append()
{
    NArray *ptr = create(1);
    push(ptr,12);
    push(ptr,3);
    assert(*(ptr->data)== 12);
    assert(*(ptr-> data + 1)== 3);
    Free(ptr);
}

void test_resize()
{
    NArray *ptr = create(1);
    assert((ptr->capacity)== 16);
    for(int i=0;i<15;i++)
    {
        push(ptr,i);
    }
    assert((ptr->capacity) == 32);

   for(int i=0;i<15;i++)
   {
       pop(ptr);
   } 
   assert((ptr->capacity) == 16);
    
    Free(ptr);
}

void test_empty()
{
    NArray *ptr = create(1);
    bool empty = is_empty(ptr);
    assert(empty==1);
    push(ptr,1);
    empty = is_empty(ptr);
    assert(empty==0);
    Free(ptr);
}


void test_at()
{
    NArray *ptr = create(1);
    for(int i=0;i<4;i++)
    {
        push(ptr,i);
    }

    assert(at(ptr,1) == 1);
    Free(ptr);
}

void test_insert()
{
    NArray *ptr = create(4);
    for(int i=0;i<4;i++)
    {
        insert(ptr,i,i+2);
    }

    assert(at(ptr,0) == 2);
    assert(at(ptr,1) == 3);
    assert(at(ptr,2) == 4);
    Free(ptr);
}

void test_prepend()
{
    NArray *ptr = create(2);
    prepend(ptr,3);
    prepend(ptr,4);
    assert(at(ptr,0) == 4);
    assert(at(ptr,1) == 3);
    Free(ptr);
}

void test_pop()
{
    NArray *ptr = create(2);
    push(ptr,4);
    push(ptr,3);
    assert(pop(ptr) == 3);
    assert(pop(ptr) == 4);
    assert(size(ptr)==0);
    Free(ptr);
}

void test_remove()
{
    NArray *ptr = create(5);
    push(ptr,5);
    push(ptr,7);
    push(ptr,6);
    push(ptr,8);
    push(ptr,10);
    Nremove(ptr,8);
    assert(size(ptr) == 4);
    Free(ptr);
}

void test_find()
{
    NArray *ptr = create(6);
    push(ptr,5);
    push(ptr,9);
    push(ptr,10);
    push(ptr,12);
    assert(find(ptr,9) == 1);
    assert(find(ptr,10) == 2);
    assert(find(ptr,8)== -1);
    Free(ptr);
}
