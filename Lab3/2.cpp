#include <bits/stdc++.h>
using namespace std;

class Stack {
    vector<char> v;
    public:
     char pop(){
        if(!v.empty()){
            char c=v.back();
            v.pop_back();
            return c;
        }
        return '0';
    }
    bool isEmpty(){
        return v.empty();
    }
    void push(char c) {
        v.push_back(c);
    }
    char peek() {
        if (!v.empty()) return v.back();
        return '\0';  // return null character if stack is empty
    }
};
    bool isValid(string st){
        Stack s1 ;
        Stack s2 ;
        Stack s3 ;
        for(char c: st)
        {
            if(c=='{') s1.push(c);
            if(c=='(') s2.push(c);
            if(c=='[') s3.push(c);
            if(c==']'){
                if(!s3.isEmpty()) s3.pop();
            }
            if(c=='}'){
                if(!s1.isEmpty()) s1.pop();
            }
            if(c==')'){
                if(!s2.isEmpty()) s2.pop();
            }
            
        }
        if(!s1.isEmpty()||!s2.isEmpty()||!s3.isEmpty()) return false;
    }
    // Add stack implementation here


int main() {
    // Do not change this.
    string st;

    cin>>st;

    // Check if parentheses are valid and print 1 or 0
    std::cout << (isValid(st) ? 1 : 0) << std::endl;

    return 0;
}