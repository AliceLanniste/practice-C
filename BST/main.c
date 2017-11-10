#include<assert.h>
#include<stdio.h>
#include "bst.h"


int main(void)
{
    Node *node = NULL;

    node = insert(node,4);
    node = insert(node,12);
    node = insert(node, 2);
    node =insert(node,10);


    assert(is_in_tree(node,4));
    assert(is_in_tree(node,12));
    assert(is_in_tree(node,2));
    assert(is_in_tree(node,10));
    assert(!is_in_tree(node,0));

    assert(get_height(node) == 2);


    return 0;
}