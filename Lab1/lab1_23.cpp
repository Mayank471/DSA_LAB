#include <iostream>
#include <vector>

using namespace std;

int IndicesIncrementAndEvenCounter(const vector<vector<int>>& index, int n, int m) {
    // Write your solving function here
    //increment the rows and columns of the indices and then return the count of even values
    vector<int> row(n,0);
    vector<int> column(m,0);
   
    for (const vector<int>&ind : index)
    {
        int ni=ind[0];
        int mi=ind[1];
        while(ni<n&&mi<m){
        row[ni]++;
        column[mi]++;}
    }
    int evenCount = 0;
    for (int i=0; i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            int value=row[i]+column[j];
            if (value%2==0)evenCount++;
        }
    }
   return evenCount;
}

int main() {
    int n, m, index_len;
    cin >>n>>m;
    cin>>index_len;
     // Write your code for taking input (n,m,index_len,index) here:
    vector<vector<int>> index(index_len, vector<int>(2));
    for (int i=0;i<index_len;i++) {
        cin>>index[i][0]>>index[i][1];
    }
    int evenCount=IndicesIncrementAndEvenCounter(index, n, m);
    cout <<evenCount<<endl;
    return 0;
}
