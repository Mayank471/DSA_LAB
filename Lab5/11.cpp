#include <bits/stdc++.h>

using namespace std;

class ArrayOperations {
private:
    vector<int> *arr1, *arr2;

public:
    // Constructor to initialize arrays
    ArrayOperations(vector<int> &a1, vector<int> &a2) {
        arr1 = &a1;
        arr2 = &a2;
    }
    // Function to merge the arrays alternately and print the result
    void SortNalternatingMerge() {
        sort(arr2->begin(), arr2->end(),greater<int>());
        sort(arr1->begin(), arr1->end());
        int i = 0, j = 0;
        int size1 = arr1->size();
        int size2 = arr2->size();
        while (i < size1 && j < size2) {
            cout <<(*arr1)[i]<<" ";
            i++;
            cout <<(*arr2)[j]<<" ";
            j++;
        }
        while (i < size1) {
            cout<<(*arr1)[i]<< " ";
            i++;
        }
        while (j < size2) {
            cout <<(*arr2)[j]<<" ";
            j++;
        }
    }
};

int main() {
    int n1, n2;

    // Reading the size and elements of the first array
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Reading the size and elements of the second array
    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Creating an object of ArrayOperations
    ArrayOperations arrayOps(arr1, arr2);

    // Sorting and Merging and printing the arrays
    arrayOps.SortNalternatingMerge();

    return 0;
}
