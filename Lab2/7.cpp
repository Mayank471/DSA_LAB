#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v = 0, node* nxt = NULL) {
        val = v;
        next = nxt;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val) {
        // complete this insert function
        node* newNode=new node(val);
        newNode->next=head;
        head=newNode;
    }
    void printLinkedList(){
        // don't alter this printing function
        if(head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr = curr->next;
        }
        cout <<"NULL\n";
    }

    node* deleteFront() {
        if (head == NULL) return NULL;
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};

void insertion_operation(LinkedList &l, int val) {
    // insert the new elem at the back
    l.insert(val);
}

node* deletion_operation(LinkedList &l) {
    // delete the elem from the front
    if (l.head == NULL) return NULL;
        node* temp = l.head;
        l.head = l.head->next;
        delete temp;
        return l.head;
}

int main(){
    // initialize the linked list 
    LinkedList list;
    int n;
    cin >> n;
    // take input for linked list
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }
    // take input for the operations
    int m;
    cin >> m;
    // perform operation and after the operation print the list
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            insertion_operation(list, b);
        } else if (a == 2) {
            deletion_operation(list);
        }
        list.printLinkedList();
    }

    return 0;
}
