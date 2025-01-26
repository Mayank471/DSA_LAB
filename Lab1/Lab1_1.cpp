#include<iostream>
using namespace std;
int main() {
    int n; cin >>n;
    int arr[n][n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >>arr[i][j];  
        }
    }
    if(n==1){
        cout <<arr[0][0];
        return 0;
        
    }
    for(int i=0;i<n;i++)
    sum+=arr[i][i];
    for(int i=0;i<n;i++)
    sum+=arr[i][n-i-1];
    cout <<sum<<endl;
    return 0;
}