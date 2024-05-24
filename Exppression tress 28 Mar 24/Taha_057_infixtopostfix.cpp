#include <iostream>
using namespace std;

struct stacknode {
    int value;
    stacknode* next;
};

stacknode* top = nullptr;

void push(char val) {
    stacknode *current = (stacknode *) malloc(sizeof(stacknode)); 
    current->value = val;
    current->next = NULL;

    if (top == NULL) {
    top = current;        
    }else{
        current->next = top;
        top = current;
    }
}

char topmostval ()
 {
    if (top==NULL)
    {
        cout<< "Stack underflow"<<endl;
        return 0;
    }
    else
    {
    char val = top->value;
    return val;
    }
 }


char Pop() {
    if (top == NULL){
        cout << "Stack Underflow: Cannot pop"<< endl;
        return 0;
    }
    else{
    stacknode * temp = top;
    char vall = top->value;
    top= top->next;
    delete temp; 
    return vall;
    }
}

int preced(char op){
    if(op == '/' || op=='*'||op=='%'){
        return 4;
    }if(op == '+' || op == '-'){
        return 3;
    }if(op=='<' || op== '>'){
        return 2;
    }if(op == '&' || op == '|'){
        return 1;
    }
    return 0;
}

string infixToPostfix(string &input){
    string postfixx;
    for (char i : input){
        if(isalnum(i)){
            postfixx+=i;
        }else if(i == '('){
            push(i);
        }else if(i == ')'){
            while (top != NULL && topmostval() != '(')
            {
                postfixx+=topmostval();
                Pop();    
            }
            Pop();
        }else{
            while (top != NULL && preced(topmostval()) >= preced(i))
            {
                postfixx+=topmostval();
                Pop();    
            }
            push(i);
        }

    }

// for empty the stack
    while (top!=NULL)
    {
        postfixx += topmostval();
        Pop();
    }
    return postfixx;
}
// void buildExpTree(){
    
// }

int main(){
    string infix;
    cout << "Enter an infix expression: "<< endl;
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression " << postfix<<endl;
    // buildExpTree();   
    return 0;
}






