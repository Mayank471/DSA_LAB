#include<bits/stdc++.h>
using namespace std;


class matrixClass{
public:
    int n,m;
    vector<vector<int>> M;
    matrixClass(int shape0, int shape1, vector<vector<int>> matrix){
        n = shape0;
        m = shape1;
        M = matrix;
    }
    
    void displayMatrix(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << M[i][j] << ' ';
            cout << '\n';
        }
    }

    void matrixConverter(){
        vector<vector<int>> lower_triangular(n,vector<int>(m,0));
        vector<vector<int>> upper_triangular(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i>=j) upper_triangular[i][j]=M[i][j];
                if(j>=i) lower_triangular[i][j]=M[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<upper_triangular[i][j]<<" ";
            }
            for(int j=0;j<m;j++)
            {
                cout <<lower_triangular[i][j]<<" ";
            }
            cout <<'\n';
        }
    }

};

int main()
{
    vector<vector<int>> matrix(3, vector<int>(3,0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>matrix[i][j];
        }
    }

    matrixClass M(3,3, matrix);
    M.matrixConverter();
    return 0;
}