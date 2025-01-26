#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> fillHashPatt(int n) {
    // Your code here
    vector<vector<char>> result(n,vector<char>(n , ' '));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j||i==0||i==n-1||j==0||j==n-1||i+j==n-1)result[i][j]='#';
        }
    }
    return result;
    
}

int main() {
    int n;
    
    // Taking input for the size of the matrix
    cin >> n;
    
    // Function call to generate the matrix pattern
    vector<vector<char>> result = fillHashPatt(n);
    
    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}