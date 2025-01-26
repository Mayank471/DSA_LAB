#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int key;
    int value;
    TreeNode* next;
    TreeNode* prev;
    TreeNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    int size;
    unordered_map<int, TreeNode*> cache; 
    TreeNode* head; 
    TreeNode* tail; 
    void moveToFront(TreeNode* node) {     
        remove(node);
        node->next = head->next;
        head->next->prev= node;
        head->next =node;
        node->prev = head;
    }
    void remove(TreeNode* node) {
        node->prev->next = node->next;
        node->next->prev =node->prev;
    }
    void removeLRU() {
        TreeNode* lru = tail->prev;
        remove(lru);
        cache.erase(lru->key);
        delete lru;
        size--;
    }
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new TreeNode(0, 0); 
        tail = new TreeNode(0, 0); 
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache() {
        TreeNode* curr = head;
        while (curr) {
            TreeNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    void enqueue(int x, int y)
    {
        TreeNode *newNode = new TreeNode(x,y);
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    int isEmpty(){
        return (head==nullptr);
    }
    int dequeue(){
        if (isEmpty()) {exit(EXIT_FAILURE); }
        TreeNode* popped = tail;
        int val = popped->key;
        tail = tail->prev;
        tail->next = nullptr;
        delete popped;
        size--;
        return val;
    }
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        TreeNode* node = cache[key];
        moveToFront(node);
        return node->value;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            TreeNode* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (size == capacity) {
                removeLRU();
            }
            TreeNode* newNode = new TreeNode(key, value);
            cache[key] = newNode;
            newNode->next = head->next;
            head->next->prev = newNode;
            head->next = newNode;
            newNode->prev = head;
            size++;
        }
    }
};

int main() {
    int n, numOps, op, key, value;
    cin >> n >> numOps;

    LRUCache cache(n);
    for (int i = 0; i < numOps; i++) {
        cin >> op;
        if (op == 1) {
            cin >> key;
            cout << cache.get(key) << endl;
        } else if (op == 2) {
            cin >> key >> value;
            cache.put(key, value);
        }
    }

    return 0;
}
