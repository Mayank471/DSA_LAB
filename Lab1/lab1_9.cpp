#include<bits/stdc++.h>
using namespace std;

#define rows 100
#define cols 100

void compute_matrix(int arr[rows][cols], int n, int m){
    // Complete this function
    int result[rows][cols]={0};
    int sum_row[rows]={0};
    int matrix_sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) matrix_sum+=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) sum_row[i]+=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int final=matrix_sum;
            for(int k=0;k<j+1;k++) final-=arr[i][k];
            for(int k=0;k<i;k++) final-=sum_row[k];
            result[i][j]=final;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout <<result[i][j]<<" ";
        }
        cout <<"\n";
    }
}

int main(){
    int n,m; cin>>n>>m;
    // Feel free to create any helper function if needed.
    // Add your code here.
    int arr[rows][cols];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
        {
        cin >>arr[i][j];
        }
    }
    compute_matrix(arr, n, m);
    return 0;
}