#include <iostream>
using namespace std;

int grid(int n ){
    if(n<4)return 1;
    if(n==4)return 2;
    int arr[n+1];
    for(int i=1;i<4;i++)arr[i]=1;
    arr[4]=2;
    for(int i=5;i<n+1;i++)
    arr[i]=arr[i-1]+arr[i-4];
    return arr[n];
}

int main(){
    // There's no need to change this
    int n; 
    cin>>n;
    cout<<grid(n);
    return 0;
} 