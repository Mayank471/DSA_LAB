#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiralMatrix(int n) {
    // Your code here
      vector<vector<int>> result(n, vector<int>(n, 0));
     int start = 1; 
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result[top][i] = start++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result[i][right] = start++;
        }
        right--;
        for (int i = right; i >= left; i--) {
                result[bottom][i] = start++;
            }
        bottom--;
        for (int i = bottom; i >= top; i--) {
                result[i][left] = start++;
            }
        left++;
    }
    return result;
}

int main() {
    int n;
    
    // Taking input for the size of the matrix
    cin >> n;
    
    // Function call to generate the spiral matrix
    vector<vector<int>> result = spiralMatrix(n);
    
    // Printing the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}