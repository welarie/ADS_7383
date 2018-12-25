#ifndef BST_H
#define BST_H

#include <QWidget>
#include<iostream>

class BST
{
public:
  int key;
  BST* left;
  BST* right;
  BST(int x);
bool find_add(BST* tree, int &x);
bool find(BST* tree, int &k);
BST* delete_el(BST *&tree, int &k, int gl);
BST* merge(BST* l, BST* r);
};
#endif // BST_H
