#include <bits/stdc++.h>
using namespace std;

int main(void) {
    
    int n,m; cin>>n>>m;
    int matrix[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin >>matrix[i][j];
    }
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> result;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    for (int i=0;i<result.size();i++) cout << result[i] << " ";
    return 0;
}