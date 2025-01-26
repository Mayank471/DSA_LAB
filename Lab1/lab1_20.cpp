#include <iostream>  
using namespace std;  
int main() {
   int n,m; cin>>n>>m;
   int arr[n][m];
   bool zero=true , one=true , identity= true;
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++) cin>>arr[i][j];
   }
    if (n == 1 && m == 1) {
      if (arr[0][0] == 1) {
         cout << "1\n"; 
      } else if (arr[0][0] == 0) {
         cout << "0\n"; 
      } else {
         cout << "-1\n"; 
      }
      return 0;
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
         if(arr[i][j]!=0) zero = false;
         if(arr[i][j]!=1) one =false;
         
            if((i==j &&arr[i][j]!=1)||(i!=j&&arr[i][j]!=0) )
            identity = false;
         
      }
   }
   if(zero) cout <<"0\n";
   else if(one) cout <<"1\n";
   else if(identity) cout <<"2\n";
   else cout <<"-1\n";
   return 0;
}