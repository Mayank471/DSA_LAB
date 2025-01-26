#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val=v;
        next=nxt;
    }
};

class LinkedList {
    public:
    node* head;
    LinkedList(node* h=NULL){
        head = h;
    }

    void insert(int val){
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout <<"NULL\n";
    }
};

node* concatenate(node* head1, node* head2){
    if(head1==NULL) return head2;  
    if(head2==NULL) return head1; 

    node* curr=head1;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next=head2; 
    return head1;
    // Implement the required logic
}

int main() {
    int n, m;
    cin >> n >> m;
    // make instances for the two linked lists
    LinkedList list1, list2;
    // take input for the two linked lists
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        list1.insert(val);
    }
    for (int i = 0; i < m; i++){
        int val;
        cin >> val;
        list2.insert(val);
    }
    // call the concatenate function
    node* concatenatedHead = concatenate(list1.head, list2.head);
    // Print the concatenated linked list
    LinkedList resultList(concatenatedHead);
    // print the linked list using printLinkedList function
    resultList.printLinkedList();
    return 0;
}
