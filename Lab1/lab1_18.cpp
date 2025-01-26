#include <iostream>  
using namespace std;  
int main() {
   int n; cin>>n;
   int arr[n][n];
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++) cin >>arr[i][j];
   } 
   int sum_lower=0,sum_upper=0;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         if(i>=j) sum_lower+=arr[i][j];
         if(i<=j) sum_upper+=arr[i][j];
      }
   } 
   cout <<sum_upper <<" "<<sum_lower;
   return 0;
   //code
}