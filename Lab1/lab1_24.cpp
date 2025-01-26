#include <iostream>
#include <vector>

using namespace std;

class Matrix{
    private:
    
    public:
    int n, m;
    vector<vector<int>> M;
    
    Matrix(int rowsize, int colsize){
        n = rowsize;
        m = colsize;
        M = vector<vector<int>>(n, vector<int>(m, 0));
    }
    void printMatrix() {
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cout<<M[i][j]<<" ";
        cout<<"\n";
    }
    }
    
    void add_k_matrix(int k, int row1, int col1, int row2, int col2) {
        // Add k to each element in the submatrix defined by (row1, col1) to (row2, col2)
        for(int i=min(row1,row2);i<=max(row1,row2);i++)
        {
            for(int j=min(col1,col2);j<=max(col1,col2);j++)
            {
                M[i][j]+=k;
            }
        }
    }
};


int main(){
    int n = 0, m= 0;
    
    // Input n and m here
    cin>>n>>m;
    Matrix mat(n,m);
    
    int k, row1, col1, row2, col2;
    
    // Input M matrix here
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>mat.M[i][j];
    }
    // Input k and submatrix boundaries here
    cin >>k>>row1>>col1>>row2>>col2;
    // Apply addition to the submatrix
    mat.add_k_matrix(k, row1, col1, row2, col2);
    mat.printMatrix();
    
    // Print the updated matrix
    return 0;
}