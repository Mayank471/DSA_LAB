#include <bits/stdc++.h>
using namespace std;
#define ll long long

class TriangleCounter {
private:
    ll n;                // Number of sticks
    vector<ll> lengths;  // Array to hold stick lengths

public:
    TriangleCounter(ll num, const vector<ll>& ar) : n(num), lengths(ar) {}

    ll Combination(int n , int r) {
        if (n >= r) return factorial(n) / (factorial(r) * factorial(n - r));
        return 0;
    }

    ll factorial(int n) {
        ll f = 1;
        for (int i = 1; i <= n; i++) f *= i;
        return f;
    }
    
    // Function to solve the problem and count valid combinations
    void solve() {
        if (n < 3) {
            cout << "0" << endl;
            return;
        }

        sort(lengths.begin(), lengths.end());  
        ll answer = 0;
        int i = 0;
        while(i < n) {
            int count = 1;  
            int j = i + 1;

            while (j < n && lengths[j] == lengths[i]) {
                count++;
                j++;
            }
            if (count >= 3) answer += Combination(count, 3);

            if (count >= 2 && i > 0) answer += Combination(count, 2)*i;
            
            i = j;
        }
        cout << answer << endl;
    }
};

int main() {
    ll n;
    cin >> n;
    vector<ll> ar(n);

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    TriangleCounter counter(n, ar);  // Create an object of TriangleCounter
    counter.solve();  // Call the solve method
    return 0;
}
