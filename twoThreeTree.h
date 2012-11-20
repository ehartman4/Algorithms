/*
 * twoThreeTree.h
 *
 * Class definitions for a 2-3 tree for Assignment A5
 */

#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H
#include<iostream>
#include<assert.h>

using namespace std;

// 2-3 tree node (complete)
template <class elemType>
struct nodeType {
   elemType dataLeft;             // data item on "left" side of node
   elemType dataRight;            // data item on "right" side of node
   short numData;                 // number of data items (1 or 2)
   nodeType<elemType> *left;      // pointer to left subtree
   nodeType<elemType> *middle;    // pointer to middle subtree
   nodeType<elemType> *right;     // pointer to right subtree
   nodeType<elemType> *parent;    // pointer to parent (may not need)
};

// 2-3 tree class (start)
template <class elemType>
class twoThreeTree {
   nodeType<elemType> *root;
   void doInorder (nodeType<elemType> *) const;

   // add in other methods here, if needed

public:
   twoThreeTree () {root = NULL;};              // constructor
   void insert (const elemType);                // insert an item
   void inorder () const {doInorder (root);     // inorder traversal
                          cout << endl;};
   void display () const;                       // display the tree
};
#endif