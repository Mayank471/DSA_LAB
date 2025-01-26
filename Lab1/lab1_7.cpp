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
    int solve(matrix& mat){
        if(mat.n<2 || mat.m<2) return 0;
        if(mat.M[0][0]==1 && mat.M[0][mat.m-1]==1 && mat.M[mat.n-1][0]==1 && mat.M[mat.n-1][mat.m-1]==1)
        return 1;
        else return 0;

        //write your code here, return the answer in the end.
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >>n>>m;
    // 1. Instantiate a matrix object with the input shape taken.
    matrix matrix(n,m);
    // 2. use for loop to set it's elements.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >>matrix.M[i][j];
        }
    }
    // 3. Create a solution object and call its member function solve.
    solution sol;
    int solution = sol.solve(matrix);
    // 4. print the value returned by the member solve.
    cout <<solution<<endl;

    return 0;
}