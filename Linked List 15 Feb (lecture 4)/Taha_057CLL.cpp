#include <iostream>
using namespace std;
#include <algorithm>

struct Records{
    int RollNo;
    int GPA;
    Records *next;
};

Records *head = nullptr;

void insert(){
   Records *current = (Records *) malloc(sizeof(Records)); 
   cout << "Enter Roll number"<<endl; 
   cin >> current->RollNo;
   cout << "Enter GPA"<<endl; 
   cin >> current->GPA;
   current->next = NULL;

   if (head == NULL){
        head = current;
        head->next = current;
   }else{
    Records *ptr = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = current;
    current->next = head;
   }
   
}

void print(){
    Records *curr = head;
    while (curr!=NULL){
        cout <<"\n"  <<"roll no: "<< curr->RollNo << "\n"<< "Gpa is " << curr->GPA<< endl;
        if(curr->next == head){
            break;
        }
        curr = curr -> next;
    }
    
}

void search(){
    cout<<"Enter Roll number to search" << endl;
    int Rollnumber;
    cin >> Rollnumber;
    Records *curr = head;
    bool found = false;
    while (curr!=NULL){
    if (curr->RollNo == Rollnumber){
    cout << "Detail of enter roll number is" <<"\n"  <<"roll no: "<< curr->RollNo<< "\n" << "Gpa is " << curr->GPA<< endl;
    found = true;
    break;
        }else{
            if(curr->next == head){
                break;
            }else{
                curr = curr->next;
            }
        }   
    }

    if(!found){
        cout << "Not Found"<< endl;
    }
    
}

void Deletee(){
    cout<<"Enter Roll number which you want to delete " << endl;
    int todelete;
    cin >> todelete;
    Records * curr = head;
    if(todelete == head->RollNo){
        head = head ->next;
        free(curr);
    }else{
        Records *prev = head;
        curr = head->next;
        while (curr != NULL)
        {
            if(curr->RollNo == todelete){
                prev->next = curr->next;
                free(curr);
                break;
            }else{
                if(curr-> next == head){
                    cout<<"not found"<<endl;
                    break;
                }
                curr = curr->next;
                prev = prev->next;
            }
        }
        
        if(curr == NULL){
            cout << "Not Found";
        }
    }
}

void DeleteAll() {
    Records *curr = head;
    while (curr != nullptr) {
        Records *temp = curr;
        curr = curr->next;
        free(temp);
        if (curr == head){
            break;// Check if we've reached the end of the circular list
        }
    }
    head = nullptr; // Reset head to nullptr since the list is empty now
    cout << "All data is deleted" << endl;
}


int main(){
    int a=1;
    while (a==1 || a==2 || a==3 || a==4 || a==5)
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
            break;
        }
    cout << "If you want to enter data press 1 " << endl;
    cout << "If you want to search data press 2 " << endl;
    cout << "If you want to print list press 3 " << endl;
    cout << "If you want to delete a node press 4 " << endl;
    cout << "If you want to delete all a node press 5 " << endl;
    cout << "If you want to end process press 6 " << endl;
    cin >> a;
    }

    return 0;
}
