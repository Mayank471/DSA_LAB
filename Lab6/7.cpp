#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution{
private:
    // Add helper functions or variables here if needed.
public:
    bool savingBeta(int n, vector<int>& w, ll c){
        sort(w.begin(), w.end());
        ll sum=0;
        for(int i=0;i<2*n;i++,i++) sum +=w[i];
            if(sum>=c)  return true;
            else return false;
        
        // Write your code here.
    }
};

// DO NOT ALTER THE CODE BELOW.

int main(){
    int tt; cin >> tt;
    while(tt--){

        int n; ll c; cin >> n >> c;
        vector<int> w(2*n,0); for(int i=0;i<2*n;i++) cin >> w[i];

        Solution sol; bool ans = sol.savingBeta(n,w,c);
        cout << (ans ? "yes"  :"no") << '\n';
    }
    
    return 0;
}