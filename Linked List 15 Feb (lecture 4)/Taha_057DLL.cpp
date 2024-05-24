
#include <iostream>
using namespace std;
#include <algorithm>

struct Records{
    int RollNo;
    int GPA;
    Records *next;
    Records *prev;
    int index;
};

Records *head = nullptr;

void insert(){
   Records *current = (Records *) malloc(sizeof(Records)); 
    Records * lastnode = nullptr;
   cout << "Enter Roll number"<<endl; 
   cin >> current->RollNo;
   cout << "Enter GPA"<<endl; 
   cin >> current->GPA;
   current->next = NULL;
   current->prev = NULL;

   if (head == NULL){
        head = current;
        // Past paper
        lastnode = current;
        current->index = 1;
   }else{
    Records *ptr = head;
    int count = 1;
    while(ptr->next != NULL){
        ptr = ptr->next;
        count++;
    }
    ptr->next = current;
    current->prev = ptr;

    
    // Past paper
    current->index = count+1;
    lastnode = current;

   }
   
}

void print(){
    Records *curr = head;
    while (curr!=NULL){
        cout <<"\n"  <<"roll no: "<< curr->RollNo << "\n"<< "Gpa is " << curr->GPA<< endl;
        curr = curr->next;
    }
    
}

void search(){
    cout<<"Enter Roll number to search" << endl;
    int Rollnumber;
    cin >> Rollnumber;
    Records *curr = head;
       while (curr!=NULL){
        if (curr->RollNo == Rollnumber){
cout << "Detail of enter roll number is" <<"\n"  <<"roll no: "<< curr->RollNo<< "\n" << "Gpa is " << curr->GPA<< endl;
break;
        }else{
           curr = curr->next;
        }   
    }

    if (curr == NULL)
    {
        cout << "Not found" << endl;
    }
    
    
}

void Deletee(){
    cout<<"Enter Roll number which you want to delete" << endl;
    int todelete;
    cin >> todelete;
    Records * curr = head;
    if(todelete == head->RollNo){
        head = head ->next;
        free(head);
    }else{
        while (curr != NULL)
        {
            if(curr->RollNo == todelete){
                if(curr->next != nullptr){
                    curr->next->prev = curr->prev;
                }
                if(curr->prev != nullptr){
                    curr->prev->next = curr->next;
                }
                free(curr);
                break;
            }else{
                curr = curr->next;
            }
        }
        
        if(curr == NULL){
            cout << "Not Found";
        }
    }
}

void DeleteAll(){
    Records *curr = head;
    while (curr != NULL)
    {
        head = head->next;
        free(curr);
        curr = head;
    }
    cout << "All data is deleted" << endl;
}

void bubbleSort() {
    if (head == NULL || head->next == NULL) {
        // Empty list or list with only one node is already sorted
        return;
    }

    bool swapped;
    Records *ptr;
    Records *lastPtr = NULL; // Pointer to the last node that is not sorted

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lastPtr) {
            if (ptr->RollNo > ptr->next->RollNo) {
                // Swap the RollNo
                int tempRollNo = ptr->RollNo;
                ptr->RollNo = ptr->next->RollNo;
                ptr->next->RollNo = tempRollNo;
                swapped = true;
            }
            ptr = ptr->next;
        }
        // Mark the last node as sorted
        lastPtr = ptr;
    } while (swapped);


    
}


int main(){
    int a=1;
    while (a==1 || a==2 || a==3 || a==4 || 5)
    {
        if(a==1){
        insert();
        }else if(a==2){
        search();
        }else if(a==3){
        print();
        }else if(a==4){
        Deletee();
        }else if(a==5){
        DeleteAll();
        }else if (a==6){
            bubbleSort();
        }else if (a==7){
            break;
        }
    cout << "If you want to enter data press 1 " << endl;
    cout << "If you want to search data press 2 " << endl;
    cout << "If you want to print list press 3 " << endl;
    cout << "If you want to delete a node press 4 " << endl;
    cout << "If you want to delete all a node press 5 " << endl;
cout << "If you want to sort linked list through bubble sort press 6 " << endl;
cout << "If you want to end process press 7" << endl;

    cin >> a;
    }
    
    return 0;
}


