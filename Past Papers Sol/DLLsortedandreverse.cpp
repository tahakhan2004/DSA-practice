
#include <iostream>
using namespace std;
#include <algorithm>

struct Records{
    int RollNo;
    Records *next;
    Records *prev;
    int index;
};

Records *head = nullptr;

void insert() {
    Records* current = (Records*)malloc(sizeof(Records));
    cout << "Enter Roll number" << endl;
    cin >> current->RollNo;
    current->next = NULL;
    current->prev = NULL;

    if (head == NULL) {
        head = current;
    } else {
        Records* ptr = head;
        Records* prev = NULL;
        while (ptr != NULL && ptr->RollNo < current->RollNo) {
            prev = ptr;
            ptr = ptr->next;
        }
        if (prev == NULL) {
            current->next = head;
            head->prev = current;
            head = current;
        } else {
            prev->next = current;
            current->prev = prev;
            current->next = ptr;
            if (ptr != NULL) {
                ptr->prev = current;
            }
        }
    }
}


void print(Records * start){
    Records *curr = start;
    while (curr!=NULL){
        cout <<"\n"  <<"roll no: "<< curr->RollNo << endl;
        curr = curr->next;
    }
    
}
Records* copyAndReverse(Records* start) {
    Records* newHead = nullptr;
    Records* current = start;
    while (current != nullptr) {
        Records* newNode = (Records*)malloc(sizeof(Records));
        newNode->RollNo = current->RollNo;
        newNode->next = newHead;
        newNode->prev = nullptr;
        if (newHead != nullptr) {
            newHead->prev = newNode;
        }
        newHead = newNode;
        current = current->next;
    }
    return newHead;
}


// Reverse the original list 
// void reverseList() {
//     Records* current = head;
//     Records* temp = nullptr;
//     while (current != nullptr) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }
//     if (temp != nullptr) {
//         head = temp->prev;
//     }
// }

int main(){
    int a=1;
    while (a==1 || a==2 || a==3 || a==4 || 5)
    {
        if(a==1){
        insert();
        }else if(a==2){
        print(head);
        }else if(a==3){
    Records * revHead = copyAndReverse(head);

    cout << "Reversed Copy List: ";
    print(revHead);
        }
        else if (a==4){
            break;
        }
    cout << "If you want to enter data press 1 " << endl;
    cout << "If you want to print list press 3 " << endl;
cout << "If you want to end process press 4" << endl;

    cin >> a;
    }
    
    return 0;
}






// Past Papers

// #include <iostream>
// #include <cstdlib>

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };

// Node* head = nullptr;
// Node* tail = nullptr;

// // Function to insert a node in sorted order
// void sortedInsert(int value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->prev = nullptr;
//     newNode->next = nullptr;

//     if (head == nullptr) {
//         head = tail = newNode;
//     } else if (head->data >= value) {
//         newNode->next = head;
//         head->prev = newNode;
//         head = newNode;
//     } else {
//         Node* current = head;
//         while (current->next != nullptr && current->next->data < value) {
//             current = current->next;
//         }
//         newNode->next = current->next;
//         if (current->next != nullptr) {
//             current->next->prev = newNode;
//         } else {
//             tail = newNode;
//         }
//         current->next = newNode;
//         newNode->prev = current;
//     }
// }

// // Function to print the list
// void printList(Node* start) {
//     Node* current = start;
//     while (current != nullptr) {
//         std::cout << current->data << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }

// // Function to copy the reverse of the list into a new list
// void copyReverse() {
//     Node* newHead = nullptr;
//     Node* current = tail;
//     while (current != nullptr) {
//         Node* newNode = new Node;
//         newNode->data = current->data;
//         newNode->next = newHead;
//         if (newHead != nullptr) {
//             newHead->prev = newNode;
//         } else {
//             head = newNode;
//         }
//         newHead = newNode;
//         current = current->prev;
//     }
// }

// int main() {
//     // Insert elements into the list in sorted order
//     sortedInsert(5);
//     sortedInsert(3);
//     sortedInsert(8);
//     sortedInsert(1);
//     sortedInsert(10);

//     std::cout << "Original List (sorted): ";
//     printList(head);

//     // Copy the reverse of the list into a new list
//     copyReverse();

//     std::cout << "Reversed Copy List: ";
//     printList(head);

//     return 0;
// }


// 2
// #include <iostream>
// #include <cstdlib>

// struct Node {
//     int data;
//     Node* prev;
//     Node* next;
// };

// Node* head = nullptr;
// Node* tail = nullptr;

// void insert(int value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->prev = nullptr;
//     newNode->next = nullptr;

//     if (head == nullptr) {
//         head = tail = newNode;
//     } else {
//         tail->next = newNode;
//         newNode->prev = tail;
//         tail = newNode;
//     }
// }

// void printList() {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << current->data << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }

// void reverseList() {
//     Node* current = head;
//     Node* temp = nullptr;
//     while (current != nullptr) {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     }
//     if (temp != nullptr) {
//         head = temp->prev;
//     }
// }

// int findMin() {
//     if (head == nullptr)
//         return -1; // Assuming list contains no negative numbers
    
//     int minVal = head->data;
//     Node* current = head->next;
//     while (current != nullptr) {
//         if (current->data < minVal) {
//             minVal = current->data;
//         }
//         current = current->next;
//     }
//     return minVal;
// }

// int findMax() {
//     if (head == nullptr)
//         return -1; // Assuming list contains no negative numbers
    
//     int maxVal = head->data;
//     Node* current = head->next;
//     while (current != nullptr) {
//         if (current->data > maxVal) {
//             maxVal = current->data;
//         }
//         current = current->next;
//     }
//     return maxVal;
// }

// int main() {
//     // Insert elements into the list
//     insert(5);
//     insert(3);
//     insert(8);
//     insert(1);
//     insert(10);

//     std::cout << "Original List: ";
//     printList();

//     // Reverse the list
//     reverseList();
//     std::cout << "Reversed List: ";
//     printList();

//     // Find minimum element in the list
//     std::cout << "Minimum element in the list: " << findMin() << std::endl;

//     // Find maximum element in the list
//     std::cout << "Maximum element in the list: " << findMax() << std::endl;

//     return 0;
// }