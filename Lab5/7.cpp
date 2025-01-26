#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    Node* returnHead() {
        return head;
    }
    // Function to append a new node to the linked list
    void insert(int new_data) {
        Node* new_node = new Node(new_data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
};
int countConsecutive(Node* head, const vector<int>& ids) {
    vector<int> sorted_ids = ids;
    sort(sorted_ids.begin(), sorted_ids.end());
    int total_count = 0;
    int n = sorted_ids.size();
    int p1 = 0;
    while (p1 < n) {
        int p2 = p1;
        while (p2 + 1 < n && sorted_ids[p2 + 1] == sorted_ids[p2] + 1)p2++;
        int length = p2 - p1 ;
        total_count += length * (length + 1) / 2;
        p1 = p2 + 1;
    }
return total_count;
}

int main() {
    int n, m;
    cin >> n;

    vector<int> list(n);
    for (int i = 0; i < n; i++)
        list[i] = i;

    cin >> m;

    vector<int> ids(m);
    for (int i = 0; i < m; i++)
        cin >> ids[i];

    LinkedList linkedList;
    // Append elements to the linked list
    for (int i = 0; i < n; i++)
        linkedList.insert(list[i]);
     // Calculate and print the count of consecutive elements
    cout << countConsecutive(linkedList.returnHead(), ids) << endl;

    return 0;
}
 