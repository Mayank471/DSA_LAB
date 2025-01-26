#include<bits/stdc++.h>
using namespace std;

int main(){
    int size1; cin>>size1;
	int size2 = size1;
	vector<int> A(size1);
	vector<int> B(size2);

	for (int i = 0; i < size1; i++) cin>>A[i];
    for (int i = 0; i < size2; i++) cin>>B[i];


    //write your code here
    vector<int> R , M;
	sort(A.begin(),A.end());
    sort(B.begin(),B.end());
        int i=0,j=0;
        while(i<size1&&j<size2){
            if(A[i]==B[j])
            {
                if(R.empty()||R.back()!=A[i]) R.push_back(A[i]);
                i++; j++;
            }
            else if(A[i]>B[j]) j++;
            else i++;
           
        }
    
    for(int i=0;i<R.size();i++)
    cout <<R[i]<<" ";
    
    return 0;
}