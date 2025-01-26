#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v) : val(v), next(NULL) {}
};

class LinkedList {
public:
    node* head;
    LinkedList(node*h = NULL) {
        head = h;
    }
     void insert(int val) {
        node* newNode=new node(val);
        if(head==NULL)
        head=newNode; 
        else{
        node* curr = head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = newNode;
        }
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "EMPTY\n";
            return;
        }
        node* curr = head;
        while (curr) {
            cout << curr->val << ' ';
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    node* second_highest() {
        if(head==NULL||head->next==NULL)return NULL;
        int firstMax=INT_MIN,secondMax=INT_MIN;
        node* curr=head;

        while(curr){
            if(curr->val>firstMax) {
                secondMax=firstMax;
                firstMax = curr->val;
            }else if(curr->val>secondMax&&curr->val<firstMax){
                secondMax=curr->val;
            }
            curr=curr->next;
        }
        if(secondMax==INT_MIN)return NULL;
        curr=head;
        while(curr){
            if(curr->val==secondMax) return curr;
            curr=curr->next;
        }
        return NULL;
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    node* result = list.second_highest();

    if (result) {
        cout << result->val << endl;
    } else {
        cout << "NULL" << endl;
    }

    return 0;
}
