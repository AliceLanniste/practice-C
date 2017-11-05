#include<stdlib.h>

Node* insert(Node *node,const int value)
{
    if(node ==NULL)
    {
        node = malloc(sizeof(Node));
        node -> value = value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if(value<node->value)
    {
        node->left = insert(node->left,value);        
    } else if(value > node->value)
    {
        node->right = insert(node->right,value);
    }
    return node;
}

