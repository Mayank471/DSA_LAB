#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Node structure for the stack
struct TreeNode {
    string data;
    TreeNode* next;
    TreeNode(string value) : data(value), next(NULL) {}
};

// Stack class using a linked list
class Stack {
private:
    TreeNode* top;
public:
    Stack() : top(NULL) {}

    void push(const string& data) {
        TreeNode* newNode=new TreeNode(data);
        newNode->next=top;
        top=newNode;
    }

    string pop(){
        if (isEmpty()) throw runtime_error("Stack underflow");
        TreeNode* temp=top;
        string popped=top->data;
        top=top->next;
        delete temp;
        return popped;
    }

    bool isEmpty() const {
        return top == NULL;
    }     
     ~Stack() {
        while (!isEmpty()) pop();
    }
};

bool isOperator(char ch) 
{
    return (ch =='+'||ch=='-'||ch =='*'||ch=='/'||ch=='^');
}
// Function to convert prefix to postfix
string prefixToPostfix(const string& prefix) {
    Stack stack;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalpha(ch)) stack.push(string(1, ch));
        else if (isOperator(ch)) {
            string operand1= stack.pop();
            string operand2= stack.pop();
            string postfix= operand1 + operand2 + ch;
            stack.push(postfix);
        }
    }
    return stack.pop();
}

int main() {
    string prefix;
    cin >> prefix;

    try {
        string postfix = prefixToPostfix(prefix);
        cout << postfix << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
