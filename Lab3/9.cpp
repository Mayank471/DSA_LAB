#include <iostream>
using namespace std;
#define MAX 100

// Queue structure
class Queue {
private:
    int items[MAX];
    int front, rear, size;

public:
    // Constructor to initialize the queue
    Queue() : front(0),rear(-1),size(0){}
    // TODO: Initialize front and rear
    // Check if the queue is full
    bool isFull() {
        return size==MAX;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size==0;
    }

    // Enqueue an element
    void enqueue(int value) {
        // TODO: Add an element to the queue if it is not full
        if (isFull()) return;
        rear=(rear+1)%MAX;
        items[rear]=value;
        size++;
    }

    // Dequeue an element
    int dequeue() {
        // TODO: Remove and return the front element of the queue if it is not empty
        if(isEmpty()) {
            return -1;
        }
        int value=items[front];
        front=(front+1)%MAX;
        size--;
        return value;
    }

    // Get the front element
    int getFront() {
        if (isEmpty())return -1;
        return items[front];
    }

    // Print and empty the entire queue
    void printWholeQueue() {
        while (!isEmpty()){
            cout<<dequeue()<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Queue q;

    int n;
    cin >> n;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }
    // TODO: Print the front element using getFront()
    cout << q.getFront() << endl;
    // TODO: Dequeue and print an element using dequeue()
    cout << q.dequeue() << endl;
    // TODO: Print and empty the whole queue using printWholeQueue()
    q.printWholeQueue();
    // TODO: Print if the queue is full using isFull()
    cout << (q.isFull() ? 1 : 0) << endl;
    // TODO: Print if the queue is empty using isEmpty()
    cout << (q.isEmpty() ? 1 : 0) << endl;

    return 0;
}
