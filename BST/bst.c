#include<stdlib.h>
#include "bst.h"
#include <stdio.h>

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

int get_node_count(Node *tree)
{
    if(tree== NULL)
    {
        return 0;
    }

    return 1 + get_node_count(tree->left)+get_node_count(right);
}


void print_tree(Node *node)
{
    if(node == NULL)
        return ;

    print_tree(node->left);
    printf("%d\n",node->value);
    print_tree(node->right);
}


void delete_tree(Node *node)
{
    if(node== NULL)
        return; 

    delete_tree(node->left);
    delete_tree(node->right);
    free(node);  
}

bool is_in_tree(Node *node,int value)
{
    if (node==NULL) return false;

    if(value < node->value)
    {
        is_in_tree(node->left);
    }
    else if(value > node->value)
    {
        is_in_tree(node->right);
    }
    return true;
}


int get_height(Node *node)
{
    if(node==NULL) return 0;

    return 1+ left_or_right(get_height(node->left),get_height(node->right));
}


int left_or_right(int value1,int value2)
{
    if(value1 >= value2)
    {
        return value1;
    }
    else
    {
        return value2;
    }
}


int get_min(Node *node)
{
    if (node==NULL)
        return ;

    Node *current = node;    
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current -> value;
}


int get_max(Node *node)
{
    if(node==NULL)
        return ;

    Node *current = node;

    while(current->right != NULL)
    {
        current = current->right;
    }

    return current->value;
}


bool is_binary_search_tree(Node *node)
{
    if(node==NULL)  return false;
}


Node* delete_value(Node *node,int value)
{
    if(node==NULL)
    return node;

    if(value< node->value)
    {
        node->left=delete_value(node->left,value);
    }
    else if(value > node->value)
    {
        node->right = delete_value(node->right,value);
    }
    else
    {
        if(node->left == NULL && node->right== NULL)
        {
            free(node);
            node = NULL;
        }
        else if(node->left == NULL)
        {
            Node *temp = node;
            node = node->right;
            free(temp);
        }
        else if(node->right == NULL)
        {
            Node *temp = node;
            node = node->right;
            free(temp);
        }
        else{
            int right_min = get_min(node->right);
            node->value = right_min;
            node->right = delete_value(node->right,right_min);

        }

    }
    return node;
}