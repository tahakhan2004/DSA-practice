#include <iostream>
using namespace std;

struct stacknode {
    int value;
    stacknode* next;
};

stacknode* top = nullptr;

void push(int val) { 
    stacknode *current = new stacknode;
    current->value = val;
    current->next = NULL;

    if (top == NULL) {
        top = current;        
    } else {
        current->next = top;
        top = current;
    }
}

int topmostval() {
    if (top == NULL) {
        cout << "Stack underflow" << endl;
        return 0;
    } else {
        return top->value;
    }
}

int Pop() {
    if (top == NULL) {
        cout << "Stack Underflow: Cannot pop" << endl;
        return 0;
    } else {
        stacknode* temp = top;
        int vall = top->value;
        top = top->next;
        delete temp;
        return vall;
    }
}

int preced(char op) {
    if (op == '/' || op == '*' || op == '%') {
        return 4;
    } else if (op == '+' || op == '-') {
        return 3;
    } else if (op == '<' || op == '>') {
        return 2;
    } else if (op == '&' || op == '|') {
        return 1;
    }
    return 0;
}

string infixToPostfix(string &input) {
    string postfixx;
    for (char i : input) {
        if (isalnum(i)) {
            postfixx += i;
        } else if (i == '(') {
            push(i);
        } else if (i == ')') {
            while (top != NULL && topmostval() != '(') {
                postfixx += topmostval();
                Pop();    
            }
            Pop();
        } else {
            while (top != NULL && preced(topmostval()) >= preced(i)) {
                postfixx += topmostval();
                Pop();    
            }
            push(i);
        }
    }

    while (top != NULL) {
        postfixx += topmostval();
        Pop();
    }
    return postfixx;
}

int postfixEvaluation(string pf) {
    for (int i = 0; i < pf.length(); i++) {
        if (isdigit(pf[i])) {
            push(pf[i] - '0');
        } else {
            int op2 = Pop();  
            int op1 = Pop();  

            switch (pf[i]) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '<':
                    push(op1 < op2);
                    break;
                case '>':
                    push(op1 > op2);
                    break;
            }
        }
    }
    return topmostval();
}

int main() {
    string infix;
    cout << "Enter an infix expression: " << endl;
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    string postfixx;
    cout << "Enter a postfix expression to evaluate (0-9): " << endl;
    getline(cin, postfixx);
    int evaluatePostfix = postfixEvaluation(postfixx); 
    cout << "Evaluation result: " << evaluatePostfix << endl;
    
    return 0;
}
