#include <iostream>
using namespace std;

// Node class representing each element in the stack
class TreeNode {
public:
    int data;
    TreeNode* next;

    // Constructor to initialize node
    TreeNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class to handle stack operations
class Stack {
private:
    TreeNode* topNode; // Pointer to the top node in the stack

public:
    // Constructor to initialize stack
    Stack() {
        topNode = nullptr;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Function to push an element onto the stack
    void push(int x) {
        TreeNode* newNode=new TreeNode(x);
        newNode->next=topNode;
        topNode=newNode;
    }

    // Function to pop the top element from the stack
    void pop() {
        if(isEmpty()) return;
        TreeNode* temp=topNode;
        topNode=topNode->next;
        delete temp;
    }

    // Function to get the top element of the stack
    int top() {
        if(isEmpty()){
            return -1;
        }
        return topNode->data;
    }

    // Function to print all elements of the stack
    void printStack() {
        if(isEmpty()) return;
        TreeNode* current = topNode;
        while(current!=NULL){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
};

// Main function to process queries
int main() {
    Stack stack;
    int q;
    cin >> q; // Number of queries
    for(int i=0;i<q;i++){
        int query;
        cin >> query;
        switch(query){
            case 1: { 
                int x;
                cin >> x;
                stack.push(x);
                break;
            }
            case 2: { 
                stack.pop();
                break;
            }
            case 3: { 
                cout << stack.top() << endl;
                break;
            }
            case 4: {
                stack.printStack();
                break;
            }
            default: break;
        }
    }
    return 0;
}
