#include <iostream>
#include <algorithm>
using namespace std;
// struct BSTNode
// {
//   int value;
//   int HeightFromLeft;
//   int HeightFromRight;
//   BSTNode *LeftChild;
//   BSTNode *RightChild;
// };

// int MaximumHeight(int a, int b)
// {
//   if (a>b)
//   {
//     return a;
//   }
//   return b;
// }

// BSTNode *shiftLeft(BSTNode *UBNode)
// {
//   BSTNode *CurrNode = UBNode->RightChild;
//   BSTNode *Temp = CurrNode->LeftChild;
//   CurrNode->LeftChild = UBNode;
//   UBNode->RightChild = Temp;
//   if (Temp == NULL)
//   {
//     UBNode->HeightFromRight = 0;
//   }
//   else
//   {
//     UBNode->HeightFromRight = MaximumHeight(Temp->HeightFromLeft, Temp->HeightFromRight) + 1;
//   }
//   CurrNode->HeightFromLeft = MaximumHeight(UBNode->HeightFromLeft, UBNode->HeightFromRight) + 1;
//   return CurrNode;
// }

// BSTNode *shiftRight(BSTNode *UBNode)
// {
//   BSTNode *CurrNode = UBNode->LeftChild;
//   BSTNode *Temp = CurrNode->RightChild;
//   CurrNode->RightChild = UBNode;
//   UBNode->LeftChild = Temp;
//   if (Temp == NULL)
//   {
//     UBNode->HeightFromLeft = 0;
//   }
//   else
//   {
//     UBNode->HeightFromLeft = MaximumHeight(Temp->HeightFromLeft, Temp->HeightFromRight) + 1;
//   }
//   CurrNode->HeightFromRight = MaximumHeight(UBNode->HeightFromLeft, UBNode->HeightFromRight) + 1;
//   return CurrNode;
// }

// BSTNode *insert(BSTNode *root, int value)
// {
//   if (root == NULL)
//   {
//     BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
//     node->value = value;
//     node->HeightFromLeft = node->HeightFromRight = 0;
//     node->LeftChild = node->RightChild = NULL;
//     return node;
//   }
  
//   if (value > root->value)
//   {
//     root->RightChild = insert(root->RightChild, value);
//     root->HeightFromRight = MaximumHeight(root->RightChild->HeightFromLeft, root->RightChild->HeightFromRight) + 1;
//   }
//   else if (value < root->value)
//   {
//     root->LeftChild = insert(root->LeftChild, value);
//     root->HeightFromLeft = MaximumHeight(root->LeftChild->HeightFromLeft, root->LeftChild->HeightFromRight) + 1;
//   }
//   int balanceFactor = root->HeightFromLeft - root->HeightFromRight;
  
// if (balanceFactor > 1)
//   {
//     if (value < root->LeftChild->value)
//     {
//       root = shiftRight(root);
//     }
//     else    // double shifting
//     {
//       root->LeftChild = shiftLeft(root->LeftChild);
//       root = shiftRight(root);
//     }
//   }
// else if (balanceFactor < -1)
//   {
//     if (value > root->RightChild->value)
//     {
//       root = shiftLeft(root);
//     }
//     else
//     {
//       root->RightChild = shiftRight(root->RightChild);
//       root = shiftLeft(root);
//     }
//   }
//   return root;
// }

//     bool search(BSTNode *root, int toSearch)
//     {
//     if (root == NULL)
//     {
//         return false;
//     }
//     if (toSearch == root->value)
//     {
//         return true;
//     }
//     if (toSearch < root->value)
//     {
//         search(root->LeftChild, toSearch);
//     }
//     else if (toSearch > root->value)
//     {
//         search(root->RightChild, toSearch);
//     }
//     return false;
//     }

// void inOrderTraversial(BSTNode *root)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   inOrderTraversial(root->LeftChild);
//   cout << root->value << " ";
//   inOrderTraversial(root->RightChild);
// }


// int main()
// {
//   BSTNode *root = NULL;
//   int a;
//   do
//   {
//     cout << "Enter 1 to Insert a value" << endl
//          << "Enter 2 to Search a value" << endl
//          << "enter 3 to print In Order Traversial" << endl
//          << "Enter 4 to End the program " << endl;
//     cin >> a;
//     if (a == 1)
//     {
//       int value;
//       cout << "Enter a value to Insert : ";
//       cin >> value;
//       root = insert(root, value);
//     }
//     else if (a == 2)
//     {
//       int toSearch;
//       cout << "Enter a value to Search  : ";
//       cin >> toSearch;
//       bool isAvailable = search(root, toSearch);
//       isAvailable ? cout << "Value found  " << endl : cout << "Value not Found " << endl;
//     }
//     else if (a == 3)
//     {
//       inOrderTraversial(root);
//       cout << endl;
//     }
    
//     else if (a == 4)
//     {
//       cout << "Good Bye" << endl;
//     }
//     else
//     {
//       cout << "please enter a valid number" << endl;
//     }
//   } while (a != 4);
// }

#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    int Height;
    BSTNode *LeftChild;
    BSTNode *RightChild;

    BSTNode(int key) : data(key), Height(1), LeftChild(nullptr), RightChild(nullptr) {}

    int height(BSTNode *N)
    {
        if (N == nullptr)
            return 0;
        return N->Height;
    }

    int maxHeight(int a, int b)
    {
        if (a > b)
            return a;
        else
            return b;
    }

    BSTNode *rightRotate(BSTNode *y)
    {
        BSTNode *x = y->LeftChild;
        BSTNode *T2 = x->RightChild;

        // Perform rotation
        x->RightChild = y;
        y->LeftChild = T2;

        // Update heights
        y->Height = maxHeight(height(y->LeftChild), height(y->RightChild)) + 1;
        x->Height = maxHeight(height(x->LeftChild), height(x->RightChild)) + 1;

        // Return new root
        return x;
    }

    BSTNode *leftRotate(BSTNode *x)
    {
        BSTNode *y = x->RightChild;
        BSTNode *T2 = y->LeftChild;

        // Perform rotation
        y->LeftChild = x;
        x->RightChild = T2;

        // Update heights
        x->Height = maxHeight(height(x->LeftChild), height(x->RightChild)) + 1;
        y->Height = maxHeight(height(y->LeftChild), height(y->RightChild)) + 1;

        // Return new root
        return y;
    }

    int getBalance(BSTNode *N)
    {
        if (N == nullptr)
            return 0;
        return height(N->LeftChild) - height(N->RightChild);
    }

    BSTNode *insert(BSTNode *node, int key)
    {
        /* 1.  Perform the normal BST insertion */
        if (node == nullptr)
            return new BSTNode(key);

        if (key < node->data)
            node->LeftChild = insert(node->LeftChild, key);
        else if (key > node->data)
            node->RightChild = insert(node->RightChild, key);
        else // Equal keys are not allowed in BST
            return node;

        /* 2. Update height of this ancestor node */
        node->Height = maxHeight(height(node->LeftChild), height(node->RightChild)) + 1;

        /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
        int balance = getBalance(node);

        // If this node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->LeftChild->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->RightChild->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->LeftChild->data)
        {
            node->LeftChild = leftRotate(node->LeftChild);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->RightChild->data)
        {
            node->RightChild = rightRotate(node->RightChild);
            return leftRotate(node);
        }

        /* return the (unchanged) node pointer */
        return node;
    }

    void preOrder(BSTNode *root)
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            preOrder(root->LeftChild);
            preOrder(root->RightChild);
        }
    }
};

int main()
{
    BSTNode *root = nullptr;

    // Example usage of insert function
    root = root->insert(root, 10);
    root = root->insert(root, 20);
    root = root->insert(root, 30);
    root = root->insert(root, 40);
    root = root->insert(root, 50);
    root = root->insert(root, 25);

    // Displaying the resulting tree (preorder traversal)
    cout << "Preorder traversal of the constructed AVL tree is: ";
    root->preOrder(root);
    cout << endl;

    return 0;
}
