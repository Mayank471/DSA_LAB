#include <iostream>  
using namespace std;  
int main() {
   int n,m; cin >>n>>m;
   int arr[n][m];
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         cin>>arr[i][j];
      }
   }
   for(int i=0;i<n;i++)
   {
      for(int j =0;j<n;j++)
      {
         int sum=0;
         if(j==m-1) arr[i][j]=0;
         else {
            for(int k=j+1;k<m;k++)
            {
               sum+=arr[i][k];
            }
         arr[i][j]=sum;
         }
      }
   }
    for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         cout<<arr[i][j];
      }
      cout <<"\n";
   }
   
   //code
}