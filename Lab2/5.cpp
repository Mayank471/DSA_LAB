#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val = v;
        next = nxt;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h=NULL) {
        head = h;
    }
    void insert(int val) {
        node* newNode=new node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        node* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next = newNode;
        // complete this insert function
    }
    void printLinkedList(){
        if (head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr=head;
        while(curr){
            cout<<curr->val<<' ';
            curr=curr->next;
        }
        cout <<"NULL\n";
    }
};

node* concatenate(node* head1,node* head2){
    if (!head1) return head2; 
    if (!head2) return head1;
    node* curr = head1;
    while (curr->next != NULL) curr = curr->next;
    curr->next = head2;
    return head1;
}
node* sortedConcatenate(node* head1, node* head2) {
    if(!head1)return head2;
    if(!head2)return head1;
    node* dummy=new node();
    node* tail=dummy;
    while(head1 && head2){
        if(head1->val<=head2->val){
            tail->next=head1;
            head1=head1->next;
        }else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }
    if(head1)tail->next=head1;
    else tail->next=head2;
    return dummy->next;
    // Implement the required logic here
}
int main() {
    int n, m;
    cin >> n >> m;
    // Initialize two linked lists
    LinkedList list1, list2;
    // take input and make the linked lists    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list1.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        list2.insert(x);
    }
    // call the sortedConcatenate function
    node* mergedHead = sortedConcatenate(list1.head, list2.head);
    LinkedList mergedList(mergedHead);
    // print the new sorted big linked list using printLinkedList
    mergedList.printLinkedList();
    return 0;
}
