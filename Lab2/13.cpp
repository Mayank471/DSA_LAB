#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* prev;
    TreeNode* next;

    TreeNode(int v = 0, TreeNode* p = nullptr, TreeNode* n = nullptr) {
        data = v;
        prev = p;
        next = n;
    }
};

class DoubleLinkedList {
public:
    TreeNode* head;
    DoubleLinkedList(TreeNode* h = nullptr) {
        head = h;
    }

    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        TreeNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void printLinkedList() {
        if (head == nullptr) {
            cout << "\n";
            return;
        }

        TreeNode* curr = head;
        while (curr != nullptr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << "\n";
    }
};

DoubleLinkedList concatenate(DoubleLinkedList& l1, DoubleLinkedList& l2) {
    if(l1.head==nullptr) return l2;
    if(l2.head==nullptr) return l1;
    TreeNode* curr=l1.head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next=l2.head;
    l2.head->prev=curr;
    return l1;
}

DoubleLinkedList sortedConcatenate(DoubleLinkedList& l1, DoubleLinkedList& l2) {
    DoubleLinkedList result;
    TreeNode* dummy=new TreeNode(); 
    TreeNode* tail=dummy;

    TreeNode* curr1=l1.head;
    TreeNode* curr2=l2.head;

    while(curr1&&curr2){
        if (curr1->data<=curr2->data){
            tail->next=curr1;
            curr1->prev=tail;
            curr1=curr1->next;
        } else {
            tail->next=curr2;
            curr2->prev=tail;
            curr2=curr2->next;
        }
        tail=tail->next;
    }
    tail->next=(curr1)?curr1:curr2;
    if(tail->next){
        tail->next->prev=tail;
    }
    result.head=dummy->next;
    if(result.head){
        result.head->prev=nullptr;
    }
    delete dummy; 
    return result;
}
DoubleLinkedList insertSorted(DoubleLinkedList& l, int val) {
    TreeNode* newNode=new TreeNode(val);

    if(l.head==nullptr||l.head->data>=val){
        newNode->next=l.head;
        if(l.head!=nullptr){
            l.head->prev=newNode;
        }
        l.head=newNode;
        return l;
    }
    TreeNode* curr=l.head;
    while(curr->next!=nullptr&&curr->next->data<val) curr=curr->next;
    newNode->next=curr->next;
    if (curr->next!=nullptr) {
        curr->next->prev=newNode;
    }
    curr->next=newNode;
    newNode->prev=curr;
    return l;
}

int secondHighest(DoubleLinkedList& l) {
    if(l.head==nullptr||l.head->next==nullptr) return -1;
    
    int first=INT_MIN,second=INT_MIN;
    TreeNode* curr=l.head;

    while(curr!=nullptr){
        if (curr->data > first) {
            second=first;
            first=curr->data;
        }else if(curr->data>second&&curr->data<first){
            second=curr->data;
        }
        curr=curr->next;
    }
    return (second==INT_MIN) ? -1 : second;
}
void pairSumGreaterThanX(DoubleLinkedList& l, int x) {
    if (l.head==nullptr) {
        cout<<-1<<endl;
        return;
    }
    vector<int> values;
    TreeNode* curr=l.head;

    while(curr!=nullptr){
        values.push_back(curr->data);
        curr=curr->next;
    }
    sort(values.begin(),values.end());
    int count=0;
    int left=0,right=values.size()-1;
    while(left<right){
        if(values[left]+values[right]>x){
            count+=(right-left);
            right--;
        }
        else left++;
    }
    if(count==0) cout<<-1<<endl;
    else cout<<count<<endl;
}

int main() {
    int queryType;
    cin >> queryType;
    if (queryType == 1) {
        int n, m;
        cin >> n >> m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        while (m--) {
            cin >> x;
            list2.insert(x);
        }
        concatenate(list1, list2).printLinkedList();
    } else if (queryType == 2) {
        int n, m;
        cin >> n >> m;
        DoubleLinkedList list1;
        DoubleLinkedList list2;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        while (m--) {
            cin >> x;
            list2.insert(x);
        }
        sortedConcatenate(list1, list2).printLinkedList();
    } else if (queryType == 3) {
        int n;
        cin >> n;
        int x;
        DoubleLinkedList list1;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        int k;
        cin >> k;
        insertSorted(list1, k).printLinkedList();
    } else if (queryType == 4) {
        int n;
        cin >> n;
        DoubleLinkedList list1;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        cout << secondHighest(list1) << endl;
    } else if (queryType == 5) {
        int n, k;
        cin >> n >> k;
        DoubleLinkedList list1;
        int x;
        while (n--) {
            cin >> x;
            list1.insert(x);
        }
        pairSumGreaterThanX(list1, k);
    }
    return 0;
}
