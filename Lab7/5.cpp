#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Helper function to swap elements
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify up: Maintain max-heap property after insertion
    void heapify_up(size_t index) {
        if (index == 0) return;

        size_t parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapify_up(parent);
        }
    }

    // Heapify down: Maintain max-heap property after extraction
    void heapify_down(size_t index) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t largest = index;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[largest], heap[index]);
            heapify_down(largest);
        }
    }

public:
    // Insert an element into the priority queue
    void push(int value) {
        heap.push_back(value); 
        heapify_up(heap.size() - 1);
    }

    // Extract the element with the highest priority
    int pop() {
        if (heap.empty()) {
            return -1;
        }

        int max_value = heap[0];   
        heap[0] = heap.back();     
        heap.pop_back();           
        heapify_down(0);         

        return max_value;
    }
};

int main() {
    PriorityQueue pq;
    int n;
    cin >> n;

    vector<int> results;

    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;

        if (op == 1) {
            int p;
            cin >> p;
            pq.push(p);  // Call to student's implementation
        } else if (op == 2) {
            int result = pq.pop();  // Call to student's implementation
            results.push_back(result);
        }
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
