#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int val) : value(val), next(nullptr) {}
};

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->value;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* reverseSegment(ListNode *head, int left, int right) {
    if(!head||left==right) return head;

    ListNode *prev=nullptr,*current=head;
    for (int i=1;current&&i<left;i++) {
        prev=current;
        current=current->next;
    }
    ListNode *start=current;
    ListNode *then=current->next;
    for (int i=0;i<right-left;i++) {
        start->next=then->next;
        then->next=current;
        current=then;
        then=start->next;
    }
    if(prev) prev->next = current;
    else head = current;
    return head;
}

int main() {
    int value;
    ListNode *head = nullptr, *tail = nullptr;
    while (cin >> value) {
        if (value == -1) break;
        ListNode *newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int left, right;
    cin >> left >> right;

    cout << "Original list: ";
    printList(head);

    head = reverseSegment(head, left, right);

    cout << "Modified list: ";
    printList(head);
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
