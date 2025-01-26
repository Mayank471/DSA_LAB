#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store k largest elements
    int k;

public:
    KthLargest(vector<int>& nums, int k) {
        this->k = k;
        for (int num : nums) {
            insert(num);
        }
    }

    void insert(int val) {
        if (minHeap.size() < k) minHeap.push(val);
             else if (val > minHeap.top()) {
            minHeap.pop();       
            minHeap.push(val);  
        }
    }

    int getKthLargest() {
        if (minHeap.size() < k) return -1; 
        
        return minHeap.top(); 
    }
};

int main() {
    int n, k, streamSize;

    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cin >> streamSize;
    vector<int> stream(streamSize);

    for (int i = 0; i < streamSize; i++) {
        cin >> stream[i];
    }

    KthLargest kthLargest(arr, k);

    vector<int> output;
    output.push_back(kthLargest.getKthLargest());  

    for (int val : stream) {
        kthLargest.insert(val);  
        output.push_back(kthLargest.getKthLargest());  
    }
    cout << "[-1";  
    for (size_t i = 1; i < output.size(); i++) {  
        cout << ", " << output[i];
    }
    cout << "]" << endl;

    return 0;
}
