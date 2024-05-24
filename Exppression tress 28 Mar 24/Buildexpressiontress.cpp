#include <iostream>
#include <stdlib.h>
using namespace std;

struct Exptree
{
  char value;
  Exptree *left;
  Exptree *right;
};

struct stackNode
{
  Exptree *node;
  stackNode *next;
};

stackNode *top = NULL;

void push(Exptree *node){
  stackNode *ptr = (stackNode *)malloc(sizeof(stackNode));
  ptr->node = node;
  ptr->next = top;
  top = ptr;
}

Exptree *pop()
{
  if (top == NULL)
  {
    return NULL;
  }
  Exptree *node = top->node;
  stackNode *tmp = top;
  top = top->next;
  free(tmp);
  return node;
}

Exptree *buildExpressionTree(string postfixEq)
{
  for (int i = 0; i < postfixEq.length(); i++)
  {
    char currChar = postfixEq[i];
    if ((currChar > 47 && currChar < 58) || (currChar > 64 && currChar < 123))
    {
      Exptree *node = (Exptree *)malloc(sizeof(Exptree));
      node->value = currChar;
      node->left = node->right = NULL;
      push(node);
    }
    else
    {
      Exptree *node = (Exptree *)malloc(sizeof(Exptree));
      node->value = currChar;
      node->right = pop();
      node->left = pop();
      push(node);
    }
  }
  Exptree *root = pop();
  return root;
}

void postOrderTraversal(Exptree *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->value << " ";
}

int main()
{
  string postfixEq1 = "abc*d/x*+fd*-";
  Exptree *root = buildExpressionTree(postfixEq1);
  postOrderTraversal(root);
}