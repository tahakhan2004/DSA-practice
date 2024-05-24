#include <iostream>
using namespace std;
#include <algorithm>

struct Records {
    int RollNo;
    int GPA;
    Records* next;
};

Records * front = NULL;
Records * rear = NULL;

void Enqueue() {
    Records *current = (Records *) malloc(sizeof(Records)); 
    cout << "Enter Roll number: ";
    cin >> current->RollNo;
    current->next = NULL;

    if (front == NULL && rear == NULL) {
        front = current;
        rear = current;        
    }else{
        rear->next = current;
        rear=current;
    }
}

void print() {
    Records* curr = front;
    while (curr != nullptr) {
        cout << "Roll no: " << curr->RollNo  << endl;
        curr = curr->next;
    }
}

void DeQueue() {
    if(front == NULL && rear == NULL){
        cout << "EMPTY"<<endl;         
    } else{
        Records * temp = front;
    front = front->next;
    cout << temp->RollNo << endl;
    delete temp;   
    //   if (front == NULL) {
    //         rear = NULL; 
    //     }
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
            Enqueue();
        } else if (a == 2) {
            DeQueue();
        } else if(a==3) {
            print();
        }else if(a==4) {
            break;
        }
    }

    return 0;
}





// Array Implementation
// int front = -1;
// int rear= -1;

// void Enqueue(int arr[], int siz){
//     int inp;
//     cout << "Enter the value to store"<< endl;
//     cin >> inp;
//     if (rear == siz-1){
//         cout << "stack overflow"<<endl;
//     }else{
//         rear++;
//         // cout << top<<endl;
//         arr[rear] = inp;
//     }
    
//     if(front == -1){
//         front++;
//     }
// }

// void DeQueue(int arr[]){
//     if(front == -1 || front > rear){
//         cout << "Stack inderflow"<< endl;
        
//     }else{
//     cout << arr[front++] << endl;
//     arr[--front] = -1;
//     }
// }

// void print(int arr[], int size){
//  for(int i=0; i < size;i++){
//         cout << arr[i]<<endl;
//     }
// }

// int main() {
//     int a;
//     int size;
//     cout << "Enter the size of the array" << endl;
//     cin >> size;
//     int arr[size];
//     while (true) {
//         cout << "\nIf you want to enque data press 1\n";
//         cout << "If you want to deque data press 2\n";
//         cout << "If you want to print press 3\n";
//         cout << "If you want to end process press 4\n";
//         cout << "Your choice: ";
//         cin >> a;

//         if (a == 1) {
//             Enqueue(arr, size);
//         } else if (a == 2) {
//             DeQueue(arr);
//         } else if(a==3) {
//             print(arr, size);
//         }else if(a==4) {
//             break;
//         }
//     }

//     return 0;
// }
