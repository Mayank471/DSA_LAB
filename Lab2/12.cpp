#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode* sublist;

    ListNode(int x) : val(x), next(nullptr), sublist(nullptr) {}
};

// Function to combine elements of all sublists level by level
ListNode* combineListsLevelByLevel(vector<ListNode*>& subLists) {
    if (subLists.empty()) return nullptr;

    queue<ListNode*> q;
    for (ListNode* head:subLists) {
        if(head)q.push(head);
    }

    ListNode* temp=new ListNode(0);
    ListNode* tail=temp;

    while (!q.empty()){
        ListNode* current=q.front();
        q.pop();
        tail->next=current;
        tail=tail->next;
        if(current->next) q.push(current->next);
        if(current->sublist) q.push(current->sublist);
    }

    return temp->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<ListNode*> subLists(n, nullptr);

    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;

        ListNode* temp = new ListNode(0);
        ListNode* current = temp;

        for (int j = 0; j < size; ++j) {
            int val;
            cin >> val;
            current->next = new ListNode(val);
            current = current->next;
        }

        subLists[i] = temp->next;
    }

    ListNode* combinedHead = combineListsLevelByLevel(subLists);
    printList(combinedHead);

    return 0;
}
