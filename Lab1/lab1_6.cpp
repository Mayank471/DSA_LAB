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
        //write your code here, return the sum in the end.
        int sum=0;
        for(int i=0;i<mat.m;i++) sum+=mat.M[0][i];
        for(int i=0;i<mat.m;i++) sum+=mat.M[mat.n-1][i];
        for(int i=1;i<mat.n-1;i++) sum+=mat.M[i][mat.m/2];
        return sum;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    // 1. Instantiate a matrix object with the input shape taken.
    int n,m; cin>>n>>m;
    matrix mat(n,m);
    // 2. use for loop to set it's elements.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >>mat.M[i][j];
        }
    }
    if(n==1||m==1)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            sum+=mat.M[i][j];
        }
        cout <<sum<<endl;
        return 0;
    }
    // 3. Create a solution object and call its member function solve.
    solution add;
     int result = add.solve(mat);
    // 4. print the value returned by the member solve.
    cout <<result;

    return 0;
}