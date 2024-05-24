
// #include <iostream>
// using namespace std;
// #include <algorithm>

// struct Records{
//     int RollNo;
//     int GPA;
//     Records *next;
// };

// Records *head = nullptr;

// void insert(){
//    Records *current = (Records *) malloc(sizeof(Records)); 
//    cout << "Enter Roll number"<<endl; 
//    cin >> current->RollNo;
//    cout << "Enter GPA"<<endl; 
//    cin >> current->GPA;
//    current->next = NULL;

//    if (head == NULL){
//         head = current;
//    }else{
//     Records *ptr = head;
//     while(ptr->next != NULL){
//         ptr = ptr->next;
//     }
//     ptr->next = current;
//    }
   
// }

// void print(){
//     Records *curr = head;
//     while (curr!=NULL){
//         cout <<"\n"  <<"roll no: "<< curr->RollNo << "\n"<< "Gpa is " << curr->GPA<< endl;
//         curr = curr->next;
//     }
    
// }

// void search(){
//     cout<<"Enter Roll number to search" << endl;
//     int Rollnumber;
//     cin >> Rollnumber;
//     Records *curr = head;
//        while (curr!=NULL){
//         if (curr->RollNo == Rollnumber){
// cout << "Detail of enter roll number is" <<"\n"  <<"roll no: "<< curr->RollNo<< "\n" << "Gpa is " << curr->GPA<< endl;
// break;
//         }else{
//            curr = curr->next;
//         }   
//     }

//     cout << "Not Found"<< endl;
    
// }

// void Deletee(){
//     cout<<"Enter Roll number which you want to delete" << endl;
//     int todelete;
//     cin >> todelete;
//     Records * curr = head;
//     if(todelete == head->RollNo){
//         head = head ->next;
//         free(head);
//     }else{
//         Records *prev = head;
//         curr = head->next;
//         while (curr != NULL)
//         {
//             if(curr->RollNo == todelete){
//                 prev->next = curr->next;
//                 free(curr);
//                 break;
//             }else{
//                 curr = curr->next;
//                 prev = prev->next;
//             }
//         }
        
//         if(curr == NULL){
//             cout << "Not Found";
//         }
//     }
// }

// void DeleteAll(){
//     Records *curr = head;
//     while (curr != NULL)
//     {
//         head = head->next;
//         free(curr);
//         curr = head;
//     }
//     cout << "All data is deleted" << endl;
// }

// int main(){
//     int a=1;
//     while (a==1 || a==2 || a==3 || a==4 || 5)
//     {
//         if(a==1){
//         insert();
//         }else if(a==2){
//         search();
//         }else if(a==3){
//         print();
//         }else if(a==4){
//         Deletee();
//         }else if(a==5){
//         DeleteAll();
//         }else if (a==6){
//             break;
//         }
//     cout << "If you want to enter data press 1 " << endl;
//     cout << "If you want to search data press 2 " << endl;
//     cout << "If you want to print list press 3 " << endl;
//     cout << "If you want to delete a node press 4 " << endl;
//     cout << "If you want to delete all a node press 5 " << endl;

// cout << "If you want to end process press 6 " << endl;
//     cin >> a;
//     }
    
//     return 0;
// }


#include <iostream>
using namespace std;
#include <algorithm>


struct Records {
    int RollNo;
    int GPA;
    Records* next;
};

Records* head = nullptr;

void insert() {
    // Records* current = new Records();
   Records *current = (Records *) malloc(sizeof(Records)); 
    cout << "Enter Roll number: ";
    cin >> current->RollNo;
    cout << "Enter GPA: ";
    cin >> current->GPA;
    current->next = nullptr;

    if (head == nullptr) {
        head = current;
    } else {
        Records* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = current;
    }
}

void print() {
    Records* curr = head;
    while (curr != nullptr) {
        cout << "Roll no: " << curr->RollNo << ", GPA: " << curr->GPA << endl;
        curr = curr->next;
    }
}

void search() {
    cout << "Enter Roll number to search: ";
    int Rollnumber;
    cin >> Rollnumber;
    Records* curr = head;
    while (curr != nullptr) {
        if (curr->RollNo == Rollnumber) {
            cout << "Detail of entered roll number is" << endl;
            cout << "Roll no: " << curr->RollNo << ", GPA: " << curr->GPA << endl;
            return;
        }
        curr = curr->next;
    }

    cout << "Not Found" << endl;
}

void Deletee() {
    cout << "Enter Roll number which you want to delete: ";
    int todelete;
    cin >> todelete;
    Records* curr = head;
    Records* prev = nullptr;
    while (curr != nullptr) {
        if (curr->RollNo == todelete) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Deleted successfully." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Roll number not found." << endl;
}

void DeleteAll() {
    Records* curr = head;
    while (curr != nullptr) {
        Records* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    cout << "All data is deleted." << endl;
}

int getNumLists() {
    Records* curr = head;
    int count = 0;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
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
            DeleteAll();
        } else if (a == 6) {
            cout << "Number of lists present: " << getNumLists() << endl;
            // break;
        } else if(a==7) {
            break;
        }
    }

    return 0;
}
