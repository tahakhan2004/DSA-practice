// #include <iostream>
// using namespace std;
// #include <algorithm>

// struct Records {
//     int RollNo;
//     int GPA;
//     Records* next;
// };

// Records* top = nullptr;

// void push() {
//     Records *current = (Records *) malloc(sizeof(Records)); 
//     cout << "Enter Roll number: ";
//     cin >> current->RollNo;
//     current->next = NULL;

        

//     if (top == NULL) {
//     top = current;        
//     }else{
//         current->next = top;
//         top = current;
//     }
// }

// void print() {
//     Records* curr = top;
//     while (curr != nullptr) {
//         cout << "Roll no: " << curr->RollNo  << endl;
//         curr = curr->next;
//     }
// }


// void Pop() {
//     if (top == NULL){
//         cout << "Stack Underflow: Cannot pop"<< endl;
//     }
//     else{
//     Records * temp = top;
//     top= top->next;
//     cout<< temp->RollNo << endl;
//     delete temp; 
//     }
// }

// int main() {
//     int a;
//     while (true) {
//         cout << "\nIf you want to push data press 1\n";
//         cout << "If you want to pop data press 2\n";
//         cout << "If you want to print press 3\n";
//         cout << "If you want to end process press 4\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             push();
//         } else if (a == 2) {
//             Pop();
//         } else if(a==3) {
//             print();
//         }else if(a==4) {
//             break;
//         }
//     }

//     return 0;
// }





// Stack for practice
 #include <iostream>
using namespace std;
#include <algorithm>

struct Records{
    int Rollno;
    Records * next; 
};

Records * top = nullptr;

void push(){
    Records * current = (Records *) malloc(sizeof(Records));
    cout << "Enter Roll number" <<endl;
    int roll_no;
    cin >> roll_no;
    current->Rollno = roll_no;
    current->next = NULL;

    if(current == NULL){
        cout << "Stack overflow" << endl;
    }

    if(top == nullptr){
        top = current;
    }else{
        current->next = top;
        top = current;
    }
}

void Pop(){
    if(top==NULL){
        cout << "Stack underflow: , stack is empty" << endl;
    }else{
        Records * temp = top;
        top = top->next;
        cout<< temp->Rollno << endl;
        delete temp;
    }

}

void print() {
    if(top==NULL){
        cout << "Stack underflow: , stack is empty" << endl;
    }
    Records* curr = top;
    while (curr != nullptr) {
        cout << "Roll no: " << curr->Rollno  << endl;
        curr = curr->next;
    }
}

int main() {
    int a;
    while (true) {
        cout << "\nIf you want to push data press 1\n";
        cout << "If you want to pop data press 2\n";
        cout << "If you want to print press 3\n";
        cout << "If you want to end process press 4\n";
        cout << "Your choice: ";
        cin >> a;

        if (a == 1) {
            push();
        } else if (a == 2) {
            Pop();
        } else if(a==3) {
            print();
        }else if(a==4) {
            break;
        }
    }

    return 0;
}





// Stack using array

// int top = -1;

// void pushh(int arr[], int siz){
//     int inp;
//     cout << "Enter the value to store"<< endl;
//     cin >> inp;
//     if (top == siz-1){
//         cout << "stack overflow"<<endl;
//     }else{
//         top++;
//         // cout << top<<endl;
//         arr[top] = inp;
//     }
    
// }

// void popp(int arr[]){
//     if(top == -1){
//         cout << "Stack inderflow"<< endl;
        
//     }else{
//     cout << arr[top--] << endl;
//     }
// }

// void printt(int arr[], int size){
//  for(int i=0; i < size;i++){
//         cout << arr[i]<<endl;
//     }
// }

// int main() {
//     int a;
//      int size;
//     cout << "Enter the size of the array" << endl;
//     cin >> size;
//     int arr[size];
  
//     while (true) {
//         cout << "\nIf you want to push data press 1\n";
//         cout << "If you want to pop data press 2\n";
//         cout << "If you want to print press 3\n";
//         cout << "If you want to end process press 4\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             pushh(arr, size);
//         } else if (a == 2) {
//             popp(arr);
//         } else if(a==3) {
//             printt(arr, size);
//         }else if(a==4) {
//             break;
//         }
//     }

//     return 0;
// }