#include <bits/stdc++.h>

using namespace std;

#define MX_SIZE 1000

class Stack{
    int top = -1;
    int v[MX_SIZE];

    public:
    /* Check if the stack is empty */
    int isEmpty(){
    return top==-1;// ADD YOUR CODE
    }

    /* Check if the stack is full */
    int isFull(){
    return top== MX_SIZE -1; //ADD YOUR CODE
    }

    /* Function to return the topmost element in the stack */
    int peek(){
        if(isEmpty())return -1;
        return v[top];
    //ADD YOUR CODE
    }

    /* Function to delete from the stack */
    int pop(){
    if(isEmpty()) return -1;
    return v[top--];
    //ADD YOUR CODE
    }

    /* Function to insert into the stack */
    int push(int data){
    if(isFull()) return 0;
    v[++top]=data;
    return 1;
    //ADD YOUR CODE
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

};

/* Main function */
int main(){
   
   int n,x,i;
   cin>>n;
   Stack s;
   for(i=0;i<n;i++){
        cin>>x;
        s.push(x);
   }
   x=s.peek();
   cout<<x<<endl;
   s.printWholeStack();
   x=s.pop();
   cout<<x<<endl;
   cout<<s.isFull()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}