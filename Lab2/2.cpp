#include <iostream>

class LinkedList{
    public:
        class Node{
            public:
                char data;
                Node *next;
                Node(char value){
                    this->data = value;
                    this->next = nullptr;
                }
        };
        
       int size;
        Node *root;
        
        LinkedList(){
            this->size = 0;
            this->root = nullptr;
        }
        
        ~LinkedList() {
            if (root==nullptr) return;
            Node* current = root->next;
            while (current != root) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            delete root;
        }
        
        void enqueue(char value){
            Node* newNode = new Node(value);
            if(root == nullptr){
                root = newNode;
                root->next = root;
            }
            else{
                newNode->next = root->next;
                root->next = newNode;
                root = newNode;
            }
            this->size += 1;
        }
        
        void dequeue(){
            if (root == nullptr) return;
            if(root->next == root) delete root;
            else{
                Node *deleted = root->next;
                root->next = deleted->next;
                delete deleted;
            }
            this->size--;
        };
        
        
        void traverse(){
            Node *ptr = root;
            while(ptr != nullptr)
            {
                std::cout << ptr->data <<" ";
                ptr = ptr->next;
            }
            std::cout<<std::endl;
        };
        
        
        void solution(){
            // Write your main solution code here
        }
};

int main(){
    LinkedList L;
    int size;
    std::cin >> size;
    // Input size and expression here
    L.solution();
    
    return 0;
}