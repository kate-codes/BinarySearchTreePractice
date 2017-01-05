#include "BSTree.h"

BSTree::BSTree()
{
   this->root = nullptr;
}


BSTree::~BSTree()
{
   Empty();
   delete root;
}

void BSTree::Instert(const string input)
{
   if (input == " ")
   {
      return;
   }

   //run retrieve to see if the string is already in the tree
   if (Retrieve(input))
   {
      //found in binary search tree so we increment the counter of that node
      return; 
   }
   else  //otherwise put data in the tree, and set counter to zero
   {
      if (root == NULL) //tree is empty place the input in the tree
      {
         root = new Node();
         root->count = 0;
         root->data = input;
      }
      else
      {
         Node *current = root;
         while (true)
         {

            if (input > current->data)//input string greater than current data
            {
               if (current->right == NULL)
               {
                  current->right = new Node();
                  current->right->data = input;
                  current->right->count = 0;
                  return;
               }
               else
               {
                  current = current->right; //otherwise continue traversing
               }
            }
            else if (input < current->data)//input string less than current data
            {
               if (current->left == NULL)
               {
                  current->left = new Node();
                  current->left->data = input;
                  current->left->count = 0;
                  return;
               }
               else
               {
                  current = current->left; //otherwise continue traversing
               }
            }
         }
      }
   }
}

bool BSTree::Retrieve(const string data) const
{
   return false;
}

void BSTree::Display() const
{
}

void BSTree::Empty()
{
   if (BSTree::isEmpty())
   {
      //tree is already empty, all we need to do is delete root which we do in destructor
      return;
   }
   Node *current = root;
   Empty(current->left); //traverse left node
   Empty(current->right); //traverse right node
   current->left = NULL;
   current->right = NULL;
}

void BSTree::Display(Node * current) const
{
}

void BSTree::Empty(Node *current)
{
   if (current == NULL)
   {
      //is the Node empty?
      return;
   }
   if (current->left != NULL)
   {
      Empty(current->left);
      delete current->left;
      //current->left = NULL;
   }
   if (current->right != NULL)
   {
      Empty(current->right);
      delete current->right;
      //current->right = NULL;
   }
}

bool BSTree::Retrieve(const string data, Node *& nodePointer) const
{
   return false;
}

bool BSTree::isEmpty() const
{
   if (root == NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
}
