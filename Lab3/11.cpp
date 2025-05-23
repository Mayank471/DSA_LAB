#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Function to initialize an empty stack
    void createStack() {
        elements.clear();
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Function to push an integer onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Function to pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow");
        }
        int topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    // Function to print the elements of the stack
    void printStack() const {
        for (int i = 0; i < elements.size(); i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    // Function to return the top element of the stack
    int top() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return elements.back();
    }

    // Recursive function to insert an element at the correct position in a sorted stack
    void sortedInsert(int value) {
        if (isEmpty() || top() <= value) {
            push(value);
        } else {
            int temp = pop();
            sortedInsert(value); 
            push(temp);
        }
    }

    // Recursive function to sort the given stack in ascending order
    void sortStack() {
        if (!isEmpty()) {  
            int temp = pop();  
            sortStack();   
            sortedInsert(temp);
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Stack stack;
        stack.createStack();
        
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            stack.push(k);
        }
    
        // Sorting the stack
        stack.sortStack();
    
        stack.printStack();
    }
    return 0;
}
