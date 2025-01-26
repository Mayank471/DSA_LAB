#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;
};

// Class to represent a linked list
class LinkedList {
public:
    Node* head;

    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers() {}

    // Function to display the linked list
    void print_list() {}

};
#include <bits/stdc++.h>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Class to represent a linked list
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers(LinkedList& list2) {
        LinkedList result;
        Node* num1=this->head;
        Node* num2=list2.head;
        Node* curr=nullptr;
        int carry= 0;
        while (num1 != nullptr || num2 != nullptr || carry != 0) {
            int sum =carry;
            if (num1 !=nullptr) {
                sum +=num1->data;
                num1 =num1->next;
            }
            if (num2 !=nullptr) {
                sum +=num2->data;
                num2=num2->next;
            }
            Node* newNode=new Node(sum % 10);
            carry =sum/10;
            if (result.head==nullptr) {
                result.head=newNode;
                curr=newNode;
            }else{
                curr->next =newNode;
                curr =curr->next;
            }
        }
        return result;
    }

    // Function to display the linked list
    void print_list() {
        Node* curr =head;
        while (curr !=nullptr) {
            cout<<curr->data;
            curr=curr->next;
        }
        cout <<"\n";
    }
    void create_linked_list(int num) {
        string num_str = to_string(num);
        head = nullptr;
        Node* curr = nullptr;
        for (int i = num_str.length() - 1; i >= 0; i--) {
            Node* newNode = new Node(num_str[i] - '0');
            if (head == nullptr) {
                head = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = curr->next;
            }
        }
    }
};

int main() {
    int num1, num2;

    // Input for two numbers
    cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;
    list1.create_linked_list(num1);
    list2.create_linked_list(num2);

    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(list2);

    // Displaying the result
    result.print_list();

    return 0;
}

int main() {
    int num1, num2;

    // Input for two numbers
    cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;

    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(list2);

    // Displaying the result
    result.print_list();

    return 0;
}