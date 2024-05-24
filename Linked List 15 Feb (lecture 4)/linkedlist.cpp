#include <iostream>
using namespace std;
#include <algorithm>

struct integers {
    int data;
    integers *next;
};
integers *head = nullptr;


void printLinkdlist(){
    if(head == NULL){
        cout << "Enpty";
    }
    integers *ptr = head;
    while(ptr !=NULL){
        cout << ptr->data <<endl;
        ptr = ptr->next;
    }
}

void insertatend(){
    integers *ptr = head;
    integers *current = (integers *) malloc(sizeof(integers));
    current->data = 200;
    current ->next = NULL; 

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = current; 
}
int main(){
    
    head = (integers *) malloc(sizeof(integers));
    head->data = 41;
    head ->next = NULL;
    // cout<< head->data;

    integers *current = (integers *) malloc(sizeof(integers));
    current->data = 95;
    current->next = NULL;
    
    head->next = current;

    current = (integers *) malloc(sizeof(integers));
    current->data = 100;
    current->next = NULL;

    head->next->next = current;

    insertatend();
    printLinkdlist();

    // in future do count each node of a linked list function
    return 0;
}