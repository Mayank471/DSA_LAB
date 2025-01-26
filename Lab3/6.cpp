#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;
    while (temp) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev; 
}
ListNode* findel(ListNode* A, int B) {
    ListNode* n = A;
    int m = 0;
    while (n) {
        m++;
        if (m == B) {
            break;
        }
        n = n->next;
    }
    return n; 
}
ListNode* reverseAlternateBNodes(ListNode* A, int B) {
    ListNode* prev=NULL;
    ListNode* temp=A;
    bool reverse = true;
    while (temp) {
        ListNode* k=findel(temp, B);
        if (!k){
            if (prev) {
                prev->next = temp;
            }
            break;
        }
        ListNode* n = k->next;
        k->next = NULL;
        if (reverse) {
            ListNode* new_head = reverseList(temp);
            if (temp==A) A=new_head;
            else prev->next=new_head;
            prev=temp;
        } else {
            prev->next=temp;
            prev=k;
        }
         temp=n;
        reverse=!reverse; 
    }
     return A; 
}
void append(ListNode*& head, int new_data) {
    ListNode* new_node = new ListNode(new_data);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    ListNode* last = head;
    while (last->next != nullptr) last = last->next;
    last->next = new_node;
}
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout <<endl;
}
int main() {
    ListNode* head = nullptr;
    int n, value, B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        append(head, value);
    }
    cin >> B;
    head = reverseAlternateBNodes(head, B);
    printList(head);
    return 0;
}