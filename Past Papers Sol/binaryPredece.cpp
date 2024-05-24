#include <iostream>
using namespace std;

struct BSTNode {
    float data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* node, float val) {
    if (node == NULL) {
        BSTNode* current = new BSTNode();
        current->data = val;
        current->left = current->right = NULL;
        return current;
    }

    // Insert into left sub-tree if less than or equal to current node
    if (val <= node->data) {
        node->left = insert(node->left, val);
    } else {  // Insert into right sub-tree otherwise
        node->right = insert(node->right, val);
    }
    return node;
}

// Function to search for an element in the binary tree
bool search(BSTNode* node, float val) {
    if (node == NULL) {
        return false;
    }
    if (node->data == val) {
        return true;
    }
    if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

// Function to find the predecessor of a given value in the BST
BSTNode* predecessor(BSTNode* node, float val) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == val) {
        if (node->left != NULL) {
            BSTNode* temp = node->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            return temp;
        }
    }
       if (node->data > val) {
        return predecessor(node->left, val);
    }
    return node;
}

// Function to find the successor of a given value in the BST
BSTNode* successor(BSTNode* node, float val) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == val) {
        if (node->right != NULL) {
            BSTNode* temp = node->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            return temp;
        }
    }
     if (node->data < val) {
        return successor(node->right, val);
    }
    return node;
}


// Function to count the total number of nodes in the binary tree
int countNodes(BSTNode* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int main() {
    int a;
    BSTNode* root = nullptr;

    while (true) {
        cout << "If you want to insert data press 1" << endl;
        cout << "If you want to search data press 2" << endl;
        cout << "If you want to find predecessor press 3" << endl;
        cout << "If you want to find successor press 4" << endl;
        cout << "If you want to find total number of nodes press 5" << endl;
        cout << "Your choice: ";
        cin >> a;

        if (a == 1) {
            float value;
            cout << "Enter Value to insert" << endl;
            cin >> value;
            root = insert(root, value);
        } else if (a == 2) {
            float value;
            cout << "Enter Value to search" << endl;
            cin >> value;
            if (search(root, value)) {
                cout << "Value Found" << endl;
            } else {
                cout << "Value Not Found" << endl;
            }
        } else if (a == 3) {
            float value;
            cout << "Enter Value to find predecessor" << endl;
            cin >> value;
            BSTNode* pred = predecessor(root, value);
            if (pred != NULL) {
                cout << "Predecessor: " << pred->data << endl;
            } else {
                cout << "No Predecessor Found" << endl;
            }
        } else if (a == 4) {
            float value;
            cout << "Enter Value to find successor" << endl;
            cin >> value;
            BSTNode* succ = successor(root, value);
            if (succ != NULL) {
                cout << "Successor: " << succ->data << endl;
            } else {
                cout << "No Successor Found" << endl;
            }
        } else if (a == 5) {
            cout << "Total Number of Nodes: " << countNodes(root) << endl;
        }
    }

    return 0;
}
