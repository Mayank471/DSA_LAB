#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

class Stack{
    int top;
    vector<int> v;
    int maxSize;

public:

    Stack(int size){
        v = vector<int>(size,0);
        maxSize = size;
        top = -1;
    }

    bool isEmpty(){
        return top==-1; // single boolean expression : when is the stack empty? //
    }

    bool isFull(){
        return top==maxSize-1;// single boolean expression : when is the stack full? //
    }

    int peek(){
        if(!isEmpty()) return v[top];
        return -1;
        // return the element at the top
    }

    int pop(){
        if(isEmpty()) cerr << "Popping from empty stack";
        return v[top--];
        // remomove the top element and return it
    }

    void push(int x){
        if(isFull()) cerr << "Pushing into a full stack";
        v[++top] = x;
    }

    void printWholeStack(){
        for(int i=top;i>=0;i--) cout << v[i] <<" ";
        cout<<'\n';
    }

};

ll sum_minOfSubArrays(vector<ll>& v){
    ll sum=0;
    int n = v.size();
    vector<int> back_less(n,-1);
    vector<int> front_less(n,n);
    Stack s(n);
    
    for(int i=0;i<n;i++)
    {
        while(!s.isEmpty()&&v[s.peek()] >= v[i]) s.pop();
        if(!s.isEmpty()) back_less[i]=s.peek();
        s.push(i);
    }
    s= Stack(n);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.isEmpty()&&v[s.peek()] > v[i]) s.pop();
        if(!s.isEmpty()) front_less[i]=s.peek();
        s.push(i);
    }
    for(int i=0;i<n;i++)
    {
        ll left_count=i-back_less[i];
        ll right_count=front_less[i]-i;
        sum+=v[i]*left_count*right_count;
        sum = sum%mod;
    }
    return sum;
    // Complete the function now

}

int main() {

    int n; cin >> n;
    vector<ll> v(n,0); for(int i=0;i<n;i++) cin >> v[i];

    cout << sum_minOfSubArrays(v);

    return 0;
}