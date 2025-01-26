#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void display(vector<int>& A) {
        for (auto x : A) cout << x << ' ';
        cout << '\n';
    }

    vector<int> restrictionSort(vector<int>& A, int k) {
        int n = A.size();
        // Complete the function, return a vector object in the end.
        
        vector<vector<int>> groups(k);
        
        for (int i = 0; i < n; i++) groups[i % k].push_back(A[i]);

        for (int i = 0; i < k; i++) sort(groups[i].begin(), groups[i].end());

        vector<int> result(n);
        
        for (int modindex = 0; modindex < k; modindex++) {
            int i = modindex;
            for (int j = 0; j < groups[modindex].size(); j++) {
                result[i] = groups[modindex][j];  
                i+=k;     
            }
        }
        return result;
    }

    int getSortedness(vector<int>& A) {
        int n = A.size();
        int sortedness = 0;
        
        for (int i = 1; i < n; i++) {
            if (A[i-1] <= A[i]) sortedness++;
        }
        return sortedness;
    }
};

int main() {
    int n, k; 
    cin >> n >> k;
    
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    solution sol;
    
    vector<int> A_ = sol.restrictionSort(A, k);
    sol.display(A_);

    int s = sol.getSortedness(A_);
    cout << s << '\n';

    return 0;
}
