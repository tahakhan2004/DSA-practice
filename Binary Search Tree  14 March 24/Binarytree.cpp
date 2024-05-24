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

void search(BSTNode * node, int val) {
    if(node == NULL){
        cout << "Tree is Empty" << endl;
        return;
    }
    if(node->data ==  val){
        cout<< "Value Found" << endl;
        return;
    }
    if(val < node->data){
         search(node->left, val);
    }else{
        search(node->right, val);
    }
}

void inordertraversal(BSTNode*node){
    if(node!=NULL){
        inordertraversal(node->left);
        cout << node->data << endl;
        inordertraversal(node->right);
    }
}

void preordertraversal(BSTNode*node){
    if(node!=NULL){
        cout << node->data << endl;
        preordertraversal(node->left);
        preordertraversal(node->right);
    }
}

void postordertraversal(BSTNode*node){
    if(node!=NULL){
        postordertraversal(node->left);
        postordertraversal(node->right);
        cout << node->data << endl;
    }
}

BSTNode * bstDelete(BSTNode*node, int value){
    if(node==NULL){
        cout<< "not found" << endl;
        return node;
    }
    if(value < node->data){
        node->left = bstDelete(node->left, value);
    }else if(value > node->data){
        node->right = bstDelete(node->right, value);
    }else{
    if(node->left == NULL){
        BSTNode * temp  = node->right;
        delete node;
        return temp;
    }else if(node->right == NULL){
        BSTNode * temp  = node->left;
        delete node;
        return temp;
    }else{
        BSTNode * succ = node->right;
        while(succ->left != NULL){
            succ = succ -> left;
        }
        node->data = succ->data;
        node->right = bstDelete(node->right, succ->data);
        return node;
    }   
}
return node;
}

BSTNode* minV(BSTNode* node){
    while (node->left!=NULL){
        node = node -> left;
    }
    return node;
}

BSTNode* maxV(BSTNode* node){
    while (node -> right != NULL){
        node=node->right;
    }
    return node;
}

int main() {
    int a;
    BSTNode* root = nullptr;

    while (true) {
        cout << "If you want to insert data press 1" << endl;
        cout << "If you want to serach data press 2" << endl;
        cout << "If you want to traverse using inOrder press 3" << endl;
        cout << "If you want to traverse using preOrder press 4" << endl;
        cout << "If you want to traverse using postOrder press 5" << endl;
        cout << "If you want to delete any from BST press 6"<< endl;
        cout << "If you want to find minimum from BST press 7" << endl;
        cout << "If you want to find maximum from BST press 8" << endl;
        cout << "Your choice: ";
        cin >> a;

        if (a == 1) {
            int value;
            cout << "Enter Value to insert"<< endl;
            cin >> value;
            root = insert(root, value);
        } else if (a == 2) {
            int value;
            cout << "Enter Value to search"<< endl;
            cin >> value;
            search(root, value);
        } else if(a==3) {
            inordertraversal(root);
        }else if(a==4) {
            preordertraversal(root);
        }else if(a==5){
            postordertraversal(root);
        }else if(a==6){
            int value;
            cout << "Enter Value to delete"<< endl;
            cin >> value;
           BSTNode * ptr =  bstDelete(root, value);
        }else if(a==7){
           BSTNode * minValue =  minV(root);
           cout << minValue->data << endl;
        }
        else if(a==8){
           BSTNode * maxValue =  maxV(root);
           cout << maxValue->data << endl;
        }
    }

    return 0;
}





// sohaib

// #include <iostream>
// using namespace std;
// struct BSTnode
// {
//     int data;
//     BSTnode* right;
//     BSTnode* left;
// };
// BSTnode* insert (BSTnode* node, int value)
// {
//     if (node==NULL)
//     {
//         BSTnode* node=(BSTnode*)malloc(sizeof(BSTnode));
//         node->data=value;
//         node->right=NULL;
//         node->left=NULL;
//         return node;
//     }
//     if (value<node->data)
//     {
//         node->left=insert(node->left,value);
//     }
//     else
//     {
//         node->right=insert(node->right,value);
//     }
// }
// void SearchTree (BSTnode* node, int value)
// {
//     if (node==NULL)
//     {
//         cout<<"no record found"<<"\n";
//     }
//     else if (node->data==value)
//     {
//         cout<<"record found"<<"\n";
//     }
//     else if (value<node->data)
//     {
//         SearchTree(node->left,value);
//     }
//     else
//     {
//         SearchTree(node->right,value);
//     }   
// }
// int main()
// {
//     BSTnode* Root= NULL;
//     int a=0;
//     int input=0;
//     while (a>=0 && a<4)
//     {
//     if (a==1)
//     {
//         cout<<"enter value to be stored"<<"\n";
//         cin>>input;
//         Root=insert(Root,input);
//     }
//     else if (a==2)
//     {
//         cout<<"enter value to be searched"<<"\n";
//         cin>>input;
//         SearchTree(Root,input);
//     }
//     else if(a==3)
//     {
//         cout<<"thanks for working"<< "\n"<<"RATE MY WORK OUT OF 5:"<<"\n";
//             int c = 0;
//             cin>> c;
//             cout << "Ratings  :  "<<c;
//             break;   
//     }   
//     cout<<"        select one       "<<"\n";
//     cout<<"press 1 to enter data"<<"\n";
//     cout<<"press 2 to search data "<<"\n";
//     cout<<"press 3 to end program "<<"\n";
//     cin>>a;  
//     }
//     return 0;
// }