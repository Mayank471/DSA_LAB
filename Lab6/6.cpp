#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Competition {
public:
    void solveTestCases() {
        ll n;
        cin >> n; 
        vector<ll> challenges(n);
        vector<ll> stamina(n);
        for (int i = 0; i < n; i++) {
            cin >> challenges[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> stamina[i];
        }
        cout << calculateMaxDays(n, challenges, stamina) << endl;
    }

private:
    ll calculateMaxDays(ll n, vector<ll>& challenges, vector<ll>& stamina) {
        vector<pair<ll,ll>>friends(n);
        for (int i=0;i<n;i++)  friends[i] = {stamina[i],challenges[i]};
        
        sort(friends.begin(), friends.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return (a.first-a.second)>(b.first-b.second);
        });
        ll totalDays = 0;
        ll l = 0, r = n-1;
        while (l<r) {
            ll groupStamina = friends[l].first + friends[r].first;
            ll groupChallenges = friends[l].second + friends[r].second;
            if (groupStamina>=groupChallenges) {
                totalDays++;
                l++;
                r--;
            } 
            else r--;
        }
        return totalDays;
    }
};

int main() {
    Competition competition;
    competition.solveTestCases();
    return 0;
}