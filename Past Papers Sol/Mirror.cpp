#include <iostream>
using namespace std;
#include <algorithm>

struct BSTNode {
    int data;
    BSTNode * left;
    BSTNode * right;
};

BSTNode *insert(BSTNode * node, int val) {
    if(node == NULL){
      BSTNode *current = (BSTNode *) malloc(sizeof(BSTNode)); 
        current->data = val;
        current->left = current->right = NULL;
        return current;
    }
  
    if(val < node->data){
        node->left = insert(node->left, val);
    }else{
        node->right = insert(node->right, val);
    }
    return node;
}

void mirror(BSTNode * node){
    if(node == NULL){
        return;
    }else{
        BSTNode * temp;
        mirror(node->left);
        mirror(node->right);

        temp = node->left;
        node->left = node->right;
        node->right = temp;
        
    }
}

void preordertraversal(BSTNode*node){
    if(node!=NULL){
        cout << node->data << endl;
        preordertraversal(node->left);
        preordertraversal(node->right);
    }
}


int main() {
    int a;
    BSTNode* root = nullptr;

    while (true) {
        cout << "If you want to insert data press 1" << endl;
        cout << "If you want to traverse using preOrder press 2" << endl;
        cout << "If you want to mirror press 3" << endl;

   
        cout << "Your choice: ";
        cin >> a;

        if (a == 1) {
            int value;
            cout << "Enter Value to insert"<< endl;
            cin >> value;
            root = insert(root, value);
        } else if(a==2) {
            preordertraversal(root);
        } else if(a==3) {
            mirror(root);
        }
    }

    return 0;
}














// #include <iostream>
// #include <cstdlib>

// struct Node {
//     float data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(float value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     newNode->data = value;
//     newNode->left = newNode->right = nullptr;
//     return newNode;
// }

// void insert(Node* root, float value) {
//     if (root->left == nullptr)
//         root->left = createNode(value);
//     else if (root->right == nullptr)
//         root->right = createNode(value);
//     else {
//         insert(root->left, value);
//     }
// }

// void mirrorTree(Node* root) {
//     if (root == nullptr)
//         return;

//     Node* temp = root->left;
//     root->left = root->right;
//     root->right = temp;

//     mirrorTree(root->left);
//     mirrorTree(root->right);
// }

// void printTree(Node* root) {
//     if (root == nullptr)
//         return;

//     std::cout << root->data << " ";
//     printTree(root->left);
//     printTree(root->right);
// }

// int main() {
//     // Create the binary tree
//     Node* root = createNode(1);
//     insert(root, 2);
//     insert(root, 3);
//     insert(root, 4);
//     insert(root, 5);

//     std::cout << "Original Tree: ";
//     printTree(root);
//     std::cout << std::endl;

//     // Mirror the binary tree
//     mirrorTree(root);

//     std::cout << "Mirror Image Tree: ";
//     printTree(root);
//     std::cout << std::endl;

//     return 0;
// }