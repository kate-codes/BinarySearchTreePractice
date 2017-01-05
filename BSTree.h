#pragma once
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <string>
using namespace std; 

class BSTree
{
public:
   BSTree();
   ~BSTree();
   void Instert(const string data);
   bool Retrieve(const string data) const;
   void Display() const;
   void Empty();
   bool isEmpty() const;
private:
   struct Node
   {
      Node *right;
      Node *left;
      string data; 
      int count; 
   };
   Node *root;
   void Display(Node *current) const;
   void Empty(Node *current);
   bool Retrieve(const string data, Node *&nodePointer) const;
};
#endif

