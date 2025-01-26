#include <iostream>
using namespace std;

// use this matrix
int arr[101][101];

void col_wise_sum_of_transpose(int r,int c){
    // write the logic here
    int sum=0;
    
     for(int i=0;i<r;i++)
    {sum=0;
        for(int j=0;j<c;j++)
        {
            sum+= arr[i][j];
        }
        cout<<sum<<" ";
    }
    
    // print the array
   
    
}

int main(){
    // get the rows and columns
    int r,c; cin >>r>>c;
    
    // get the matrix
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin >>arr[i][j];
        }
    }
    
    
    // call the function
    col_wise_sum_of_transpose(r,c);

    return 0;
}