#include<bits/stdc++.h>
using namespace std;
double vol(int r , int h)
{
    return 3.14*r*r*h;
}

int main(){
    int n; cin>>n;
    int l; cin>>l;
    int u; cin>>u;
    double difference = (double)(u-l)/(n-1);
    double arr[n];
    arr[0]=l; arr[n-1]=u;
    for(int i=1;i<n-1;i++) arr[i]=arr[i-1]+difference;
    double volume[n/2];
    for(int i=0;i<n/2;i++)
    {
        volume[i] = vol(arr[2*i] , arr[2*i+1]);
    }
    for(int i=0;i<n/2;i++) cout<<fixed<<setprecision(2)<<volume[i]<<" ";
    double volume_sum=0;
    for(int i=0;i<n/2;i++) volume_sum+=volume[i];
    cout <<endl<<fixed<<setprecision(2)<<volume_sum;
    double max_volume = 0,min_volume=volume[0];
    for(int i=0;i<n/2;i++)
    {
        if(volume[i]>max_volume) max_volume=volume[i];
        if(volume[i]<min_volume) min_volume=volume[i];
    }
    cout <<endl<<fixed<<setprecision(2)<<min_volume<<endl<<fixed<<setprecision(2)<<max_volume;
    //write your code here
	
    
    return 0;
}