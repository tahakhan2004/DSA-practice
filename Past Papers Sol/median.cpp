// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// struct TreeNode {
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     int level;
//     int height;
// };

// // Function to create a new TreeNode
// TreeNode* newNode(int data) {
//     TreeNode* node = new TreeNode();
//     node->data = data;
//     node->left = nullptr;
//     node->right = nullptr;
//     node->level = 1;
//     node->height = 1;
//     return node;
// }

// // Function to insert a TreeNode in the BST and update level and height
// TreeNode* insert(TreeNode* root, int data, int level) {
//     if (root == nullptr) {
//         return newNode(data);
//     }

//     if (data <= root->data) {
//         root->left = insert(root->left, data, level + 1);
//         root->left->level = level + 1;
//         root->height = max(root->height, root->left->height + 1);
//     } else {
//         root->right = insert(root->right, data, level + 1);
//         root->right->level = level + 1;
//         root->height = max(root->height, root->right->height + 1);
//     }

//     return root;
// }

// // Function to find the median of a sorted array
// int findMedian(vector<int>& arr) {
//     int n = arr.size();
//     if (n % 2 == 0) {
//         return (arr[n / 2 - 1] + arr[n / 2]) / 2;
//     } else {
//         return arr[n / 2];
//     }
// }

// // Function to divide the array into four equal parts based on the median
// void divideArray(vector<int>& arr, vector<int>& s1, vector<int>& s2, vector<int>& s3, vector<int>& s4, int median) {
//     for (int num : arr) {
//         if (num <= median / 2) {
//             s1.push_back(num);
//         } else if (num > median / 2 && num < median) {
//             s2.push_back(num);
//         } else if (num >= median && num < (2 * median) / 3) {
//             s3.push_back(num);
//         } else {
//             s4.push_back(num);
//         }
//     }
// }

// // Function to build the BST recursively
// TreeNode* buildBST(vector<int>& arr, int level) {
//     if (arr.empty()) {
//         return nullptr;
//     }

//     int median = findMedian(arr);

//     vector<int> s1, s2, s3, s4;
//     divideArray(arr, s1, s2, s3, s4, median);

//     TreeNode* root = newNode(median);
//     root->level = level;

//     root->left = buildBST(s1, level + 1);
//     root->right = buildBST(s2, level + 1);

//     insert(root, median, level);

//     if (!s3.empty()) {
//         TreeNode* s3Root = buildBST(s3, level + 1);
//         insert(root, s3Root->data, s3Root->level);
//         root->right->left = s3Root;
//     }

//     if (!s4.empty()) {
//         TreeNode* s4Root = buildBST(s4, level + 1);
//         insert(root, s4Root->data, s4Root->level);
//         root->right->right = s4Root;
//     }

//     return root;
// }

// // Function to print the level and height of each node
// void printLevelHeight(TreeNode* root) {
//     if (root == nullptr) {
//         return;
//     }

//     cout << "Node: " << root->data << ", Level: " << root->level << ", Height: " << root->height << endl;

//     printLevelHeight(root->left);
//     printLevelHeight(root->right);
// }

// // Function to deallocate memory of the tree
// void deleteTree(TreeNode* root) {
//     if (root == nullptr) {
//         return;
//     }

//     deleteTree(root->left);
//     deleteTree(root->right);
//     delete root;
// }

// int main() {
//     vector<int> arr = {3, 5, 8, 2, 1, 9, 4, 7, 6};
//     TreeNode* root = buildBST(arr, 1);

//     cout << "BST constructed with median root:" << endl;
//     printLevelHeight(root);

//     // Deallocate memory
//     deleteTree(root);

//     return 0;
// }



#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int level;
    int height;
};

// Function to create a new TreeNode
TreeNode* newNode(int data, int level) {
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->level = level;
    node->height = 1;
    return node;
}

// Function to insert a TreeNode in the BST and update level and height
TreeNode* insert(TreeNode* root, int data, int level) {
    if (root == nullptr) {
        return newNode(data, level);
    }

    if (data <= root->data) {
        root->left = insert(root->left, data, level + 1);
        root->height = max(root->height, root->left->height + 1);
    } else {
        root->right = insert(root->right, data, level + 1);
        root->height = max(root->height, root->right->height + 1);
    }

    return root;
}

// Function to find the median of a sorted array
int findMedian(int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}

// Function to divide the array into four equal parts based on the median
void divideArray(int arr[], int n, int median, int s1[], int s2[], int s3[], int s4[]) {
    for (int i = 0; i < n; i++) {
        if (arr[i] <= median / 2) {
            s1[i] = arr[i];
        } else if (arr[i] > median / 2 && arr[i] < median) {
            s2[i] = arr[i];
        } else if (arr[i] >= median && arr[i] < (2 * median) / 3) {
            s3[i] = arr[i];
        } else {
            s4[i] = arr[i];
        }
    }
}

// Function to build the BST recursively
TreeNode* buildBST(int arr[], int n, int level) {
    if (n <= 0) {
        return nullptr;
    }

    int median = findMedian(arr, n);

    TreeNode* root = newNode(median, level);

    int s1[n], s2[n], s3[n], s4[n];
    divideArray(arr, n, median, s1, s2, s3, s4);

    int i = 0;
    while (i < n && arr[i] <= median) {
        i++;
    }

    root->left = buildBST(s1, i, level + 1);
    root->right = buildBST(s2, n - i, level + 1);

    return root;
}

// Function to print the level and height of each node
void printLevelHeight(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << "Node: " << root->data << ", Level: " << root->level << ", Height: " << root->height << endl;

    printLevelHeight(root->left);
    printLevelHeight(root->right);
}

// Function to deallocate memory of the tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int arr[] = {3, 5, 8, 2, 1, 9, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = buildBST(arr, n, 1);

    cout << "BST constructed with median root:" << endl;
    printLevelHeight(root);

    // Deallocate memory
    deleteTree(root);

    return 0;
}











// #include <iostream>
// #include <cstdlib>

// using namespace std;

// struct Node {
//     int data;
//     int level;
//     Node* left;
//     Node* right;
// };

// // Function to find the median of an array
// int findMedian(int arr[], int n) {
//     if (n % 2 == 0) {
//         return (arr[n / 2 - 1] + arr[n / 2]) / 2;
//     } else {
//         return arr[n / 2];
//     }
// }

// // Function to create a new node
// Node* newNode(int data, int level) {
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->data = data;
//     node->level = level;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }

// // Function to insert a node into the tree
// void insert(Node* root, int data, int level) {
//     if (data <= root->data) {
//         if (root->left != NULL) {
//             insert(root->left, data, level + 1);
//         } else {
//             root->left = newNode(data, level + 1);
//         }
//     } else {
//         if (root->right != NULL) {
//             insert(root->right, data, level + 1);
//         } else {
//             root->right = newNode(data, level + 1);
//         }
//     }
// }

// // Function to traverse the tree and print node levels and heights
// void traverse(Node* root) {
//     if (root == NULL)
//         return;
//     cout << "Node: " << root->data << ", Level: " << root->level << endl;
//     traverse(root->left);
//     traverse(root->right);
// }

// // Function to divide the array and build the tree recursively
// Node* buildTree(int arr[], int n, int level) {
//     if (n <= 0)
//         return NULL;

//     int median = findMedian(arr, n);
//     Node* root = newNode(median, level);
//     int s1_index = 0, s2_index = 0, s3_index = 0, s4_index = 0;
//     int s1[n], s2[n], s3[n], s4[n];

//     for (int i = 0; i < n; i++) {
//         if (arr[i] <= median / 2) {
//             s1[s1_index++] = arr[i];
//         } else if (arr[i] > median / 2 && arr[i] < median) {
//             s2[s2_index++] = arr[i];
//         } else if (arr[i] > median && arr[i] < (2 * median) / 3) {
//             s3[s3_index++] = arr[i];
//         } else {
//             s4[s4_index++] = arr[i];
//         }
//     }

//     root->left = buildTree(s1, s1_index, level + 1);
//     root->right = buildTree(s2, s2_index, level + 1);
//     insert(root, median, level);
//     root->left = buildTree(s3, s3_index, level + 1);
//     root->right = buildTree(s4, s4_index, level + 1);
//     traverse(root);
//     return root;
// }

// int main() {
//     int arr[] = {3, 6, 2, 8, 5, 7, 1, 9, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     Node* root = buildTree(arr, n, 0);
//     return 0;
// }