#include <iostream>
using namespace std;

#define repeat(i,s,e) for(long long i=s;i<e;i++)

class node {
    public:
    int val;
    node* next;
    node(int v=0,node* nxt=NULL){
        val = v;
        next = nxt;
    }
};

class LinkedList{
    public:
    node* head;
    LinkedList(node* h=NULL){
        head = h;
    }
    void insert(int val){
        // complete this insert function
        node* newNode=new node(val);
        if(head==nullptr) head=newNode; 
        else {
            node* curr=head;
            while (curr->next!=nullptr){
                curr = curr->next;
            }
            curr->next=newNode;
        }
    }

    void printLinkedList() {
        // don't alter this printing function
        if (head==NULL) {
            cout <<"EMPTY\n";
            return;
        }
        node* curr = head;
        while(curr){
            cout<<curr->val<<' ';
            curr=curr->next;
        }
        cout<<"NULL\n";
    }

    void deleteFront() {
        if (head == nullptr) return;
        node* temp = head;
        head = head->next;
        delete temp;
    }
};

int main() {
    // initialize the linked list 
    LinkedList list;
    int n;
    cin >> n;
    // take input for linked list
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        list.insert(val);
    }
    // take input for the operations
    int m;
    cin >> m;
    // perform operation and after the operation print the list
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a==1){
            list.insert(b);
        } else if(a==2){
            list.deleteFront();
        }
        list.printLinkedList();
    }

    return 0;
}
