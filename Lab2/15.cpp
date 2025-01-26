#include <iostream>
using namespace std;

// Definition for a doubly linked list node.
struct TreeNode {
    int data;
    TreeNode* next;
    TreeNode* prev;
    TreeNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list.
void insert(TreeNode*& head, int data) {
    TreeNode* newNode=new TreeNode(data);
    if(!head){
        head=newNode;
        return;
    }
    TreeNode* last=head;
    while(last->next) {
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
}

// Function to delete all occurrences of a key if it appears at least twice in the doubly linked list.
void deleteIfOccursTwice(TreeNode*& head, int key) {
    int count = 0;
    TreeNode* current = head;
    while(current){
        if (current->data==key) count++;
        current=current->next;
    }

    if(count<2) return;

    current=head;
    while(current) {
        if (current->data==key) {
            TreeNode* nodeToRemove=current;
            if (current->prev) current->prev->next = current->next;
            else head = current->next;
            if(current->next) current->next->prev=current->prev;
            current = current->next;
            delete nodeToRemove;
        } else current=current->next;
    }
}

// Function to print the doubly linked list.
void printList(TreeNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n, key;
    cin >> n;
    TreeNode* head = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(head, value);
    }

    cin >> key;
    deleteIfOccursTwice(head, key);
    printList(head);

    return 0;
}
