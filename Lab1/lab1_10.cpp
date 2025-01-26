#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

class matrix{
public:
    int n,m;
    vvi M;
    matrix(int shape0, int shape1){
        n = shape0;
        m = shape1;
        M = vvi(n,vi(m,0));
    }
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }
};

class solution{
public:
    void solve(matrix& mat){
        // write your code here, print your answer here itsel
        // Hint : First compute shape of the resulting matrix.
        // Instantiate a new matrix object with this computed shape.
        // Fill the new matrix.
        // Call the displayMatrix member of the new matrix.
        vector<bool> rows(mat.n, false), column(mat.n, false);

        for(int i = 0; i < mat.n; i++) {
            for(int j = 0; j < mat.n; j++) {
                if (mat.M[i][j] != 0) {
                    rows[i] = true;  // Keep this row
                    column[j] = true;  // Keep this column
                }
            }
        }

        // Step 2: Print only the rows and columns that should be kept
        for(int i = 0; i < mat.n; i++) {
            if (rows[i]) {
                for(int j = 0; j < mat.n; j++) {
                    if (column[j]) {
                        cout << mat.M[i][j]<<" ";
                    }
                }
                cout << '\n';  // Print a new line after each row
            }
        }
    }  
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    // 1. Instantiate a matrix object with the input shape taken
    matrix matrix(n,n);
    // 2. use for loop to set it's elements
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >>matrix.M[i][j];
        }
    }
    // 3. Create a solution object and call its member function solve
    solution solution;
    solution.solve(matrix);

    return 0;
}