#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,count=0; cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++)
{
    cin >>arr[i];
}
for(int i=0;i<n;i++)
{
int num=arr[i];
vector<int> result(32,0);
for(int i=31;i>=0;i--)
{
    result[i]= num%2;
    num/=2;
}
int one_count=0;
for(int i=0;i<32;i++)
{
    if(result[i]==1) one_count++;
}
if(one_count>4) count++;
}
cout <<count;
return 0;
}