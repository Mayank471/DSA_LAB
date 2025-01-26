#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    ll k;
    vector<ll> a;
public:
    Solution(ll damage, vector<ll> v) {
        k = damage;
        a = v;
    }

    // Complete the function
    vector<ll> solve() {
        int n = a.size();
        vector<pair<ll, int>> creatures;
        
        for (int i = 0; i < n; i++) {
            ll remainder = (a[i] % k == 0) ? k : a[i] % k;
            creatures.push_back({remainder, i});
        }
        
        sort(creatures.begin(), creatures.end(), [&](pair<ll, int> p1, pair<ll, int> p2) {
            if (p1.first == p2.first) return p1.second < p2.second;
            
            return p1.first > p2.first;
        });
        
        vector<ll> result;
        
        for (auto &creature : creatures) result.push_back(creature.second);
        return result;
    }
};

// Do not change this starter code
int main(){
    ll n,k;cin>>n>>k;
    
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    Solution S(k,a);

    vector<ll> ans = S.solve();
    for(auto i:ans) cout<<i<<" ";
    return 0;
}