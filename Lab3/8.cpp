#include <bits/stdc++.h>
using namespace std;

#define elif else if
#define print(s) cout << (s) << endl
#define ll long long

class Stack {
private:
    vector<ll> data;
public:
    void push(ll val) {
        data.push_back(val);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    ll top() {
        if (!data.empty()) {
            return data.back();
        }
        return -1;
    }

    ll size() {
        return data.size();
    }

    bool empty() {
        return data.empty();
    }
};

int main() {
    ll N, K;
    cin >> N >> K;

    Stack s;
    vector<ll> popped;
    for (ll i = 0; i < N; i++) {
        ll num;
        cin >> num;
        s.push(num);
    }
    for (ll i = 0; i < min(N, K); i++) {
        popped.push_back(s.top());
        s.pop();
    }
    ll max_popped = *max_element(popped.begin(), popped.end());
    if (K <= N) print(max_popped);
        else {
        ll remaining_operations = K - N;
        if (remaining_operations % 2 == 0) print(max_popped);
            else {
            if (s.empty()) print(-1);
                else print(max_popped);
        }
    }

    return 0;
}
