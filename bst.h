#include<stdbool.h>

#ifndef PROGRAM_BST_H
#define PROGRAM_BST_H


typedef struct BST_NODE {
    BST_NODE *left;
    BST_NODE *right;
    int value；
} Node；


extern Node* insert(Node*,const int);
extern int get_node_count(Node*);
extern void delete_tree(Node*);
extern bool is_in_tree(int);
extern int get_height(Node*);
extern int get_min(Node*);
extern int get_max(Node*);
extern bool is_binary_search_tree(Node*);
extern int get_successor(Node*); 
#endif