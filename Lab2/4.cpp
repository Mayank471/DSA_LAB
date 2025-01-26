#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val=v;
        next=nxt;
        // Define node attributes here.
    }
};
class LinkedList{
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }
    void insert_sorted(int val){
        node* newNode=new node(val);
        if (head==NULL||head->val>=val){
            newNode->next=head;
            head=newNode;
            return;
        }
        node* curr = head;
        while(curr->next!=NULL&&curr->next->val<val){
            curr=curr->next;
        }
        newNode->next=curr->next;
        curr->next=newNode;
        // Add insertion logic here.
    }
    void printLinkedList() {
        if(head==NULL){
            cout<<"EMPTY\n";
            return;
        }
        node* curr=head;
        while(curr){
            cout<<curr->val<<' ';
            curr=curr->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    LinkedList list;
    // Add your code here.
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.insert_sorted(x);
    }
    list.printLinkedList();
    return 0;
}
