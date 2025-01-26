#include <bits/stdc++.h>
using namespace std;

int chess(int n){
    // Your code goes here
    if(n==1) return 3;
    if(n==2) return 8;
    int arr[n];
    arr[0]=3;arr[1]=8;
    for(int i=2;i<n;i++)
    {
        arr[i] = 2*(arr[i-1]+arr[i-2]);
    }
    return arr[n-1];
}

int main(){
    int n; cin>>n;
    
    cout<<chess(n);

    return 0;
}