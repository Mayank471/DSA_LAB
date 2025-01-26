#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; cin>>size1;
	vector<int> A(size1);
	for (int i = 0; i < size1; i++) cin>>A[i];
    //write your code here
    for(int i=0;i<size1;i++)
    {
        int num=A[i];
        vector<int> R(8,0);
        for(int i=7;i>=0;i--)
        {
            R[i] = num%2;
            num/=2;
        }
        for(int i=0;i<8;i++)cout<<R[i];
        cout<<endl;
    }
    return 0;
}