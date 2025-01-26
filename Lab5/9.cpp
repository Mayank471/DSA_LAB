#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class for the main linked list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // Function to calculate the greater array
    vector<int> calculateGreater(int size) {
        vector<int> result(size,0);
        vector<int> value;
        Node* temp =head;
        while (temp!=nullptr){
            value.push_back(temp->data);
            temp =temp->next;
        }
        stack<int> s;

        for (int i=size -1;i>= 0;i--) {
            while (!s.empty()&&value[s.top()]<=value[i])s.pop();
            if (!s.empty())result[i] = value[s.top()];
            else result[i] = 0;
            s.push(i);
        }
        return result;
    }

    // Function to print the linked list
    void printList() {
        Node* temp =head;
        while (temp !=nullptr) {
            cout << temp->data << " ";
            temp =temp->next;
        }
        cout<<endl;
    }
};

int main() {
    int size;
    cin >>size;

    LinkedList list;

    // Input the elements of the linked list
    for (int i=0; i<size;i++) {
        int data;
        cin >>data;
        list.insert(data);
    }

    // Calculate the greater array
    vector<int> greater = list.calculateGreater(size);

    // Output the greater array
    for (int i = 0; i < size; i++) {
        cout << greater[i] << " ";
    }
    cout<<endl;

    return 0;
}
