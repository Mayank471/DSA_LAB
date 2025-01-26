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

    pair<int, int> findSpikes() {
        int upSpikes = 0, downSpikes = 0;

        if(head==NULL||head->next==NULL||head->next->next==NULL) return {upSpikes, downSpikes};
        node* prev=head;
        node* curr=head->next;
        node* next=curr->next;

        while(next!=NULL) {
            if(curr->val>prev->val&&curr->val>next->val) upSpikes++;
            else if (curr->val < prev->val && curr->val < next->val) downSpikes++;
            prev=curr;
            curr=next;
            next=next->next;
        }
        return {upSpikes,downSpikes};
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

    pair<int, int> spikes = list.findSpikes();
    cout << spikes.first << " " << spikes.second << endl;

    return 0;
}
