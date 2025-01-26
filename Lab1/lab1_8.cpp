#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class solution{
public:
    int solve(vi& a, vi& b){
        // given 2 input parameters : a, b of type vector<int>
        int i=0,j=0,count =0;
        int n = a.size(), m = b.size();
        set<int> intersection;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                intersection.insert(a[i]);
                count++;
                i++;
                j++;
            }
            else if(a[i]>b[j]) j++;
            else i++;
        }
        // Return one integer : Size of the intersection array.
        // Complete this function now.
        
        return intersection.size();
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    // Write your code here
    
    // 1. Take input sizes n and m
    int n,m; cin>>n>>m;
    // 2. Instantiate 2 vector<int> objects a and b with the given sizes.
    //    hint : constructor function for class vector<int> takes 2 parameters - size and initial value.
    vi a(n,0) , b(m,0);
    // 3. Use for loop to fill their values.
    for(int i=0;i<n;i++) cin >>a[i];
    for(int i=0;i<m;i++) cin >>b[i];
    // 4. Create a solution object and call it's member solve with the parameters.
    solution sol;
    int ans = sol.solve(a , b);
    // 5. Display the returned value.
    cout <<ans<<endl;
    
    return 0;
}