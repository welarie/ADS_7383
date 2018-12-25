#include "bst.h"
#include <iostream>
using namespace std;

BST::BST(int x)
{
    key = x;
    left = right = NULL;
}

BST* destroy(BST* tree)
{
  if (left)
    delete tree->left;
  if (right)
    delete tree->right;
  delete tree;
  return tree = NULL;
    }

bool BST::find_add (BST* tree, int &k)
{
  if (tree->key > k)
  {
    if (tree->left == NULL)
    {
      tree->left = new BST(k);
      return false;
    }
      return find_add(tree->left, k);
  }
  if (tree->key < k)
  {
    if (tree->right == NULL)
    {
      tree->right = new BST(k);
      return false;
    }
    return find_add(tree->right, k);
  }
  if (tree->key == k)
    return true;
}

bool BST::find(BST* tree, int &k)
{
    if(tree == NULL)
        return false;
    if(k==tree->key)
        return true;
    else if (k<tree->key)
        return find(tree->left, k);
    else
        return find(tree->right, k);

}

BST* BST::merge(BST* l, BST* r)
{
    if( !l )
        return r;
    if( !r )
        return l;
    BST* h = r;
    BST* k;
    if (!h->left)
    {
     h->left=l;
     return h;
    }
    while(h->left)
    {
     k=h;
     h=h->left;
    }
    if (h->right)
    {
        k->left=h->right;
    }
    else
     k->left=NULL;
    h->right=r;
    h->left=l;
    return h;
}

BST* BST::delete_el(BST *&tree, int &k, int gl)
{
    if( tree==NULL )
        return tree;
    if( tree->key==k )
    {
         BST* tmp = tree->merge(tree->left, tree->right);
         tree=tmp;
         return tmp;
    }
    else if( k < tree->key )
    tree->left = tree->delete_el(tree->left, k, gl);
    else
    tree->right = tree->delete_el(tree->right, k, gl);
    return tree;
}

