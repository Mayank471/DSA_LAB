#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ArrayProcessor {
private:
    int *arr; // Pointer to hold the array elements
    int n;    // Number of elements in the array
    const int MAX_ITERATIONS = 20; // Maximum number of iterations over the array

public:
    // Constructor to initialize the array size and allocate memory
    ArrayProcessor(int size) {
        n = size;
        arr = new int[n]; // Dynamically allocate memory for the array
    }

    // Destructor to free the allocated memory
    ~ArrayProcessor() {
        delete[] arr;
    }

    // Function to input the elements of the array from the user
    void inputArray() {
        for (int i = 0; i < n; i++) cin >> arr[i];
    }

    // Function to print reversed or original groups of 3 elements
    void printReversedGroups() {
        int j=0;
        int it=0;
        while(it<20){
        stack<int>st;
        for(int k=0;k<3;k++){
        st.push(arr[j%n]);
        j++;
        if( j >= n) {
            j=j%n;
            it++;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
    
    }
};

int main() {
    int n;

    // Ask the user for the number of elements in the array
    
    cin >> n;

    if (n < 1 || n > 32) {
        return 1;
    }

    // Create an instance of ArrayProcessor
    ArrayProcessor processor(n);

    // Input the array elements
    processor.inputArray();

    // Print the reversed groups
    processor.printReversedGroups();

    return 0;
}
