// Single linked list

// #include <iostream>
// using namespace std;
// #include <algorithm>

// struct Record{
//     int roll_no;
//     Record * next;
// };

// Record * head = nullptr;

// void insert(){
//     Record * current = (Record * ) malloc(sizeof(Record));
//     cout << "enter your roll no" << endl;
//     int rollno;
//     cin >> rollno;
//     current -> roll_no = rollno;
//     current->next = NULL;

//     if (head == nullptr){
//         head = current;
//     }else{
//         Record * ptr = head;
//         while (ptr->next != NULL){
//             ptr = ptr->next;
//         }
//         ptr->next = current;
//     }
// }

// void print(){
//     Record * curr = head;
//     while (curr != NULL){
//         cout << "Roll no: " << curr->roll_no << endl;
//         curr = curr -> next;
//     }
// }

// void search(){
//     cout << "Enter roll no you want to find:" << endl;
//     int numtofind;
//     cin >> numtofind;
//     Record * curr = head;
//     while (curr != NULL){
//         if(numtofind == curr->roll_no){
//             cout << curr->roll_no << " found in the linked list" << endl;
//             return;
//         }
//            curr = curr -> next;
//     }

//     cout << "Data not found" << endl;
// }


// void Deletee(){
//     cout << "Enter the roll no which u want to delete "<< endl;
//     int todel;
//     cin >> todel;
//     Record * curr = head;
//     Record * prev = nullptr;
//     while (curr != nullptr){
//         if(todel == curr ->roll_no){
//             if(prev == nullptr){
//                 head = curr->next;
//             }else{
//                 prev->next = curr->next;
//             }
//             delete curr;
//             cout << "Node successfully deleted" << endl;
//             return;
//         }
//         prev = curr;
//         curr = curr->next;
//     }
//     cout << "Roll number not found." << endl;
// }


// void DeleteAll(){
//     Record * curr = head;
//     while (curr != NULL){
//         Record * temp = curr;
//         curr = curr->next;
//         delete temp;
//     }
//     head = nullptr;
//     cout << "All data is deleted." << endl;
// }

// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to enter data press 1\n";
//         cout << "If you want to search data press 2\n";
//         cout << "If you want to print list press 3\n";
//         cout << "If you want to delete a node press 4\n";
//         cout << "If you want to delete all nodes press 5\n";
//         cout << "If you want to count the nodes press 6\n";
//         cout << "If you want to end process press 7\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             insert();
//         } else if (a == 2) {
//             search();
//         } else if (a == 3) {
//             print();
//         } else if (a == 4) {
//             Deletee();
//         } else if (a == 5) {
//             DeleteAll();
//         } else if (a == 6) {
            // cout << "Number of lists present: " << getNumLists() << endl;
//             // break;
//         } else if(a==7) {
//             break;
//         }
//     }

//     return 0;
// }




// Circular Singly Linked List
// #include <iostream>
// using namespace std;
// #include <algorithm>

// struct Record{
//     int roll_no;
//     Record * next;
// };

// Record * head = nullptr;

// void insert(){
//     Record * current = (Record * ) malloc(sizeof(Record));
//     cout << "enter your roll no" << endl;
//     int rollno;
//     cin >> rollno;
//     current -> roll_no = rollno;
//     current->next = NULL;

//     if (head == nullptr){
//         head = current;
//         current->next = head;
//     }else{
//         Record * ptr = head;
//         while (ptr->next != head){
//             ptr = ptr->next;
//         }
//         ptr->next = current;
//         current->next = head;
//     }
// }

// void print() {
//     if (head == nullptr) {
//         cout << "List is empty." << endl;
//         return;
//     }

//     Record *curr = head;
//     cout << "Linked List:" << endl;
//     do {
//         cout << "Roll no: " << curr->roll_no << endl;
//         curr = curr->next;
//     } while (curr != head);
// }

// void search(){
//     cout << "Enter roll no you want to find:" << endl;
//     int numtofind;
//     cin >> numtofind;
//     Record * curr = head;
//     bool found = false;
//     while (curr != NULL){
//         if(numtofind == curr->roll_no){
//             cout << curr->roll_no << " found in the linked list" << endl;
//             found = true;
//             return;
//         }
//             if(curr->next == head){
//                 break;
//             }else{
//            curr = curr -> next;

//             }
//     }
//     if(!found){
//     cout << "Data not found" << endl;
//     }
// }

// void Deletee() {
//     if (head == nullptr) {
//         cout << "List is empty. Nothing to delete." << endl;
//         return;
//     }

//     cout << "Enter Roll number which you want to delete: ";
//     int todelete;
//     cin >> todelete;

//     Record *prev = nullptr;
//     Record *curr = head;

//     // Traverse the circular list using a while loop
//     while (curr->next != head) {
//         if (curr->roll_no == todelete) {
//             if (prev == nullptr) {
//                 // If the node to delete is the head node
//                 Record *last = head;
//                 while (last->next != head) {
//                     last = last->next;
//                 }
//                 head = head->next;
//                 last->next = head; // Update the next pointer of the last node
//                 delete curr;
//                 cout << "Node successfully deleted." << endl;
//                 return;
//             } else {
//                 // If the node to delete is not the head node
//                 prev->next = curr->next;
//                 delete curr;
//                 cout << "Node successfully deleted." << endl;
//                 return;
//             }
//         }
//         prev = curr;
//         curr = curr->next;
//     }

//     // Check if the last node matches the deletion criteria
//     if (curr->roll_no == todelete) {
//         if (prev == nullptr) {
//             // If the node to delete is the only node (head node)
//             delete curr;
//             head = nullptr;
//             cout << "Node successfully deleted." << endl;
//             return;
//         } else {
//             // If the node to delete is the last node
//             prev->next = head;
//             delete curr;
//             cout << "Node successfully deleted." << endl;
//             return;
//         }
//     }

//     cout << "Roll number not found." << endl;
// }

// void DeleteAll() {
//     if (head == nullptr) {
//         cout << "List is already empty." << endl;
//         return;
//     }

//     Record *curr = head;
//     Record *nextNode;

//     // Traverse the circular list and delete each node
//     while (curr != nullptr) {
//         nextNode = curr->next;
//         delete curr;
//         curr = nextNode;
//         if (curr == head)
//             break; // Break if we have traversed the whole list once
//     }

//     head = nullptr;
//     cout << "All data is deleted." << endl;
// }

// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to enter data press 1\n";
//         cout << "If you want to search data press 2\n";
//         cout << "If you want to print list press 3\n";
//         cout << "If you want to delete a node press 4\n";
//         cout << "If you want to delete all nodes press 5\n";
//         cout << "If you want to count the nodes press 6\n";
//         cout << "If you want to end process press 7\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             insert();
//         } else if (a == 2) {
//             search();
//         } else if (a == 3) {
//             print();
//         } else if (a == 4) {
//             Deletee();
//         } else if (a == 5) {
//             DeleteAll();
//         } else if (a == 6) {
//             // cout << "Number of lists present: " << getNumLists() << endl;
//             // break;
//         } else if(a==7) {
//             break;
//         }
//     }

//     return 0;
// }


// double linked list
#include <iostream>
using namespace std;
#include <algorithm>


// struct Records {
//     int RollNo;
//     int GPA;
//     Records* prev;
//     Records* next;
// };

// Records* head = nullptr;

// void insert() {
//     // Records* current = new Records();
//    Records *current = (Records *) malloc(sizeof(Records)); 
//     cout << "Enter Roll number: ";
//     cin >> current->RollNo;
//     cout << "Enter GPA: ";
//     cin >> current->GPA;
//     current->next = nullptr;
//     current->prev = nullptr;

//     if (head == nullptr) {
//         head = current;
//     } else {
//         Records* ptr = head;
//         while (ptr->next != nullptr) {
//             ptr = ptr->next;
//         }
//         ptr->next = current;
//         current->prev = ptr;
//     }
// }

// void print() {
//     Records* curr = head;
//     while (curr != nullptr) {
//         cout << "Roll no: " << curr->RollNo << ", GPA: " << curr->GPA << endl;
//         curr = curr->next;
//     }
// }

// void search() {
//     cout << "Enter Roll number to search: ";
//     int Rollnumber;
//     cin >> Rollnumber;
//     Records* curr = head;
//     while (curr != nullptr) {
//         if (curr->RollNo == Rollnumber) {
//             cout << "Detail of entered roll number is" << endl;
//             cout << "Roll no: " << curr->RollNo << ", GPA: " << curr->GPA << endl;
//             return;
//         }
//         curr = curr->next;
//     }

//     cout << "Not Found" << endl;
// }

// void Deletee() {
//     cout << "Enter Roll number which you want to delete: ";
//     int todelete;
//     cin >> todelete;
//     Records* curr = head;
//     if(todelete == head->RollNo){
// //             if (head->next != nullptr) {
//             head = head->next;
//             delete head->prev;
//             head->prev = nullptr;
//         } else {
//             // If there's only one node in the list
//             delete head;
//             head = nullptr;
//         }
//         cout << "Record deleted" << endl;
//         return;
//     }else{
//         while (curr != nullptr) {
//             if(curr->RollNo == todelete){
//                 if(curr->next != nullptr){
//                     curr->next->prev = curr->prev;
//                 }
//                 if(curr->prev != nullptr){
//                     curr->prev->next = curr->next;
//                 }

//                 delete curr;    
//                 break;
//             }
//             else{
//                 curr=curr->next;
//             }
//         }

//         if(curr == NULL){
//             cout << "Not Found" << endl;
//         }
//     }
// }

// void DeleteAll() {
//     Records* curr = head;
//     while (curr != nullptr) {
//         Records* temp = curr;
//         curr = curr->next;
//         delete temp;
//     }
//     head = nullptr;
//     cout << "All data is deleted." << endl;
// }

// int getNumLists() {
//     Records* curr = head;
//     int count = 0;
//     while (curr != nullptr) {
//         count++;
//         curr = curr->next;
//     }
//     return count;
// }

// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to enter data press 1\n";
//         cout << "If you want to search data press 2\n";
//         cout << "If you want to print list press 3\n";
//         cout << "If you want to delete a node press 4\n";
//         cout << "If you want to delete all nodes press 5\n";
//         cout << "If you want to count the nodes press 6\n";
//         cout << "If you want to end process press 7\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             insert();
//         } else if (a == 2) {
//             search();
//         } else if (a == 3) {
//             print();
//         } else if (a == 4) {
//             Deletee();
//         } else if (a == 5) {
//             DeleteAll();
//         } else if (a == 6) {
//             cout << "Number of lists present: " << getNumLists() << endl;
//             // break;
//         } else if(a==7) {
//             break;
//         }
//     }

//     return 0;
// }







////////////////////  FINAL PRACTICE   ///////////////////


// Linked List
// struct Record{
//     int Rollno;
//     Record *next;
// };

// Record * head = nullptr;

// void insert(){
//     Record * current = ( Record * ) malloc(sizeof(Record));
//     cout << "Enter roll no" << endl;
//     cin >> current->Rollno;
//     current->next = NULL;

//     if(head == NULL){
//         head = current;
//     }else{
//         Record *ptr = head;
//         while (ptr->next!=NULL){
//             ptr = ptr->next;
//         }
//         ptr->next = current;
//     }
// }

// void print (){
//     Record * current = head;
//     while (current!=NULL){
//         cout << "Roll no: " << current->Rollno << endl;
//         current =  current->next;
//     }
// }

// void search(){
//     Record * current = head;
//     int numtofind;
//     cout << "Enter the Rollno which you want to find" << endl;
//     cin >> numtofind;
//     while (current!=NULL){
//         if(current->Rollno == numtofind){
//         cout << "Roll no: " << current->Rollno << " Found in the list" << endl;
//         return;
//         }
//         current =  current->next;
//     }

//     cout << "Data not found" << endl;
// }

// void Deletee(){
//     int todel;
//     cout << "Enter the roll no you want to delete" << endl;
//     cin >> todel;

//     Record * curr = head;
//     Record * prev = nullptr;

//     while (curr!=NULL){
//         if(curr->Rollno == todel){
//             if(prev == nullptr){
//                 head = curr->next;
//             }else{
//                 prev->next = curr->next;
//             }
//             delete curr;
//             cout << "Node successfully deleted" << endl;
//             return;
//         }
//         prev = curr;
//         curr = curr->next;
//     }
    
// cout << "Roll number not found." << endl;
// }

// void DeleteAll(){
//     Record * curr = head;
//     while (curr != NULL){
//         Record * temp = curr;
//         curr = curr->next;
//         delete temp; 
//     }
//     head = nullptr;
//     cout << "All data is deleted." << endl;
// }
// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to enter data press 1\n";
//         cout << "If you want to search data press 2\n";
//         cout << "If you want to print list press 3\n";
//         cout << "If you want to delete a node press 4\n";
//         cout << "If you want to delete all nodes press 5\n";
//         cout << "If you want to count the nodes press 6\n";
//         cout << "If you want to end process press 7\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             insert();
//         } else if (a == 2) {
//             search();
//         } else if (a == 3) {
//             print();
//         } else if (a == 4) {
//             Deletee();
//         } else if (a == 5) {
//             DeleteAll();
//         } else if (a == 6) {
//             // cout << "Number of lists present: " << getNumLists() << endl;
//             // break;
//         } else if(a==7) {
//             break;
//         }
//     }

//     return 0;
// }




// Double Linked List
// struct Record{
//     int Rollno;
//     int gpa;
//     Record * prev;
//     Record * next;
// };

// Record * head = NULL;

// void insert(){
//     Record * current = (Record *) malloc(sizeof(Record));
//     cout << "enter your roll no" << endl;
//     int rollno;
//     cin >> rollno;
//     cout << "enter your gpa" << endl;
//     int gpaa;
//     cin >> gpaa;
//     current -> Rollno = rollno;
//     current ->gpa = gpaa;
//     current->prev = NULL;
//     current->next = NULL;

//     if(head == NULL){
//         head = current;
//     }else{
//         Record * ptr = head;
//         while (ptr->next != NULL){
//             ptr = ptr->next;
//         }
//         ptr->next = current;
//         current->prev = ptr;
//     }
// }

// void print (){
//     Record * current = head;
//     while (current!=NULL){
//         cout << "Roll no: " << current->Rollno << endl;
//         cout << "GPA: " << current->gpa << endl;
//         current =  current->next;
//     }
// }

// void search(){
//     Record * current = head;
//     int numtofind;
//     cout << "Enter the Rollno which you want to find" << endl;
//     cin >> numtofind;
//     while (current!=NULL){
//         if(current->Rollno == numtofind){
//         cout << "Roll no: " << current->Rollno << " Found in the list" << endl;
//         return;
//         }
//         current =  current->next;
//     }

//     cout << "Data not found" << endl;
// }

// void Deletee(){
//     int todel;
//     cout << "Enter the roll no you want to delete" << endl;
//     cin >> todel;

//     Record * curr = head;
//     if(todel == head->Rollno){
//         head = head->next;
//         delete head->prev;
//         head->prev = NULL;
//     }else{
//         while (curr!=NULL){
//             if(curr->Rollno == todel){
//                 if(curr->prev != NULL){
//                     curr->prev->next = curr->next;
//                 }
//                 if(curr->next != NULL){
//                     curr->next->prev = curr->prev;
//                 }
//                    delete curr;
//                    cout<< "Roll no Deleted"<<endl;
//                    break;
//         }else{
//             curr = curr->next;
//         }
//     }
//         if(curr == NULL){
//             cout << "Not Found" << endl;
//         }
//     }
// }

// void DeleteAll() {
//     Record * curr = head;
//     while (curr != nullptr) {
//         Record* temp = curr;
//         curr = curr->next;
//         delete temp;
//     }
//     head = nullptr;
//     cout << "All data is deleted." << endl;
// }

// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to enter data press 1\n";
//         cout << "If you want to search data press 2\n";
//         cout << "If you want to print list press 3\n";
//         cout << "If you want to delete a node press 4\n";
//         cout << "If you want to delete all nodes press 5\n";
//         cout << "If you want to count the nodes press 6\n";
//         cout << "If you want to end process press 7\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             insert();
//         } else if (a == 2) {
//             search();
//         } else if (a == 3) {
//             print();
//         } else if (a == 4) {
//             Deletee();
//         } else if (a == 5) {
//             DeleteAll();
//         } else if (a == 6) {
//             // cout << "Number of lists present: " << getNumLists() << endl;
//             // break;
//         } else if(a==7) {
//             break;
//         }
//     }

//     return 0;
// } 



// Circular Linked List
struct Record{
    int roll_no;
    Record * next;
};

Record * tail = nullptr;

void insert(){
    Record * current = (Record *) malloc(sizeof(Record));
    cout << "enter your roll no" << endl;
    cin >> current->roll_no;
    current->next = NULL;

    if (tail == nullptr){
        tail = current;
        current->next = tail;
    }
    current->next = tail->next;
    tail->next = current;
    tail = current;
}

void print(){
    Record * head = tail->next;
    do{
        cout << "Roll no: " << head->roll_no << endl;
        head = head->next;
    }while (head != tail->next);
    
}


void search(){
      cout << "Enter roll no you want to find:" << endl;
    int numtofind;
    cin >> numtofind;
    bool found = false;
    Record * head = tail->next;
    do{
         if(numtofind == head->roll_no){
            found = true;
            cout << head->roll_no << " found in the linked list" << endl;
            return;
        }
        head = head -> next;

    }while (head != tail->next);
    
    if (!found){
        cout << "Data not found" << endl;
    }
}


void Deletee()
{
    Record *curr = tail->next;
    Record *prev = tail;
    bool found = false;
    int val;
    cout << "Enter the value node you want to delete" << endl;
    cin >> val;
    do
    {
        if (curr->roll_no == val)
        {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    if (curr == tail){
        tail = prev;
    }
    else
    {
        if (curr == prev)
        {
            tail = nullptr;
        }
    }
    prev->next = curr->next;
    delete curr;
}

int main() {
    int a;
    while (true) {
        cout << "\nIf you want to enter data press 1\n";
        cout << "If you want to search data press 2\n";
        cout << "If you want to print list press 3\n";
        cout << "If you want to delete a node press 4\n";
        cout << "If you want to delete all nodes press 5\n";
        cout << "If you want to count the nodes press 6\n";
        cout << "If you want to end process press 7\n";
        cout << "Your choice: ";
        cin >> a;

        if (a == 1) {
            insert();
        } else if (a == 2) {
            search();
        } else if (a == 3) {
            print();
        } else if (a == 4) {
            Deletee();
        } else if (a == 5) {
            // DeleteAll();
        } else if (a == 6) {
            // cout << "Number of lists present: " << getNumLists() << endl;
            // break;
        } else if(a==7) {
            break;
        }
    }

    return 0;
}