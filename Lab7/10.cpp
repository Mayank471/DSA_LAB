#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    ll getLargestAP(ll k, vector<vector<ll>>& flights) {
        map<ll, ll> heightMap; 
        map<ll, ll> height;    

        for (const auto& flight : flights) {
            ll l = flight[0];
            ll r = flight[1];
            ll x = flight[2];

            heightMap[l] += x;       
            heightMap[r + 1] -= x;  
        }

        ll maxLength = 0;    
        ll currentLength = 1; 
        ll prevHeight = 0;   
        ll currentHeight = 0; 

        bool firstElement = true; 

        for (auto &entry : heightMap) {
            ll index = entry.first;
            currentHeight += entry.second; 
            
            if (!firstElement) { 
                if (currentHeight - prevHeight == k) {
                    currentLength++;
                } else {
                    currentLength = 1; 
                }
            } else {
                firstElement = false; 
            }

            prevHeight = currentHeight; 
            if (currentLength >= 2) { 
                maxLength = max(maxLength, currentLength); 
            }
        }

        return maxLength;
    }
};

int main() {
    int n; 
    ll k; 
    cin >> n >> k;
    vector<vector<ll>> flights;

    while (n--) {
        ll l, r, x; 
        cin >> l >> r >> x;
        flights.push_back({l, r, x});
    }

    cout << Solution().getLargestAP(k, flights) << endl;

    return 0;
}