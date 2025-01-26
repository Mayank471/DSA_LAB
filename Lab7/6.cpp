#include <iostream>
#include <vector>
using namespace std;

// Class to perform Heap Sort
class HeapSort {
private:
    vector<int> arr;

    // Function to heapify a subtree rooted with node i
    void heapify(int n, int i) {
        int largest = i;         
        int left = 2 * i + 1;    
        int right = 2 * i + 2;   

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);

            heapify(n, largest);
        }
    }

public:
    // Constructor to initialize the array
    HeapSort(vector<int>& input) : arr(input) {}

    // Function to perform heap sort
    void sort() {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(n, i); 
        }

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);

            heapify(i, 0);
        }
    }

    // Function to get the sorted array
    const vector<int>& getSortedArray() const {
        return arr;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // Create HeapSort object
    HeapSort heapSort(input);

    // Perform sorting
    heapSort.sort();  // Call to student's implementation

    // Print sorted array
    const vector<int>& sortedArray = heapSort.getSortedArray();
    for (size_t i = 0; i < sortedArray.size(); i++) { // Change int to size_t
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
