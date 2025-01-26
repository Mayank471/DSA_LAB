#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; cin>>size1;
	int size2 = size1;
	vector<int> A(size1);
	vector<int> B(size2);
    vector<int> C;
	for (int i = 0; i < size1; i++) cin>>A[i];
    for (int i = 0; i < size2; i++) cin>>B[i];


    //write your code here
	for(int i=0;i<size1;i++)
    {
        bool state = false;
        for(int j=0;j<size2;j++)
        {
            if(A[i]==B[j]) state = true;
        }
        if(!state) C.push_back(A[i]);
    }
    for(int i=0;i<size1;i++)
    {
        bool state = false;
        for(int j=0;j<size2;j++)
        {
            if(B[i]==A[j]) state = true;
        }
        if(!state) C.push_back(B[i]);
    }
    sort(C.begin(), C.end());
    for(int i : C)
    cout << i <<" ";
    
    
    return 0;
}