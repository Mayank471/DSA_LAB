#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Juice {
private:
    int n, k;
    vector<ll> arr;

public:
    Juice(int n, int k, vector<ll>& arr) {
        this->n = n;
        this->k = k;
        this->arr = arr;
    }
    // Complete the following function
    long long solve() {
        sort(arr.begin(), arr.end());
        if (n > k + 1) {
            for (int i = 0; i < k; i++) arr[n-1] += arr[n-2-i];
            return arr[n-1];
        } 
        else {
            for (int i = 0; i < n-1; i++) arr[n-1] += arr[i];
            return arr[n-1];
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Juice JuiceClass(n, k, arr);
    cout << JuiceClass.solve() << "\n";
    
    return 0;
}
