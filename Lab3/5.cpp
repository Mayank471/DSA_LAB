#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='^') return 3;
    return 0;
}

bool isLeftAssociative(char ch) {
    if(ch=='^') return false;
    return true;
}

void infixToPostfix(const char* infix, char* postfix) {
    stack<char> s;
    int j=0;
    for (int i=0;infix[i]!='\0';i++) {
        char c=infix[i];

        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')) postfix[j++] = c;
        else if(c=='(') s.push(c);
        else if(c==')'){
            while(!s.empty()&&s.top()!='('){
                postfix[j++]=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty()&&precedence(s.top())>precedence(c)){
                postfix[j++]=s.top();
                s.pop();
            }
            if(!s.empty()&&precedence(s.top())==precedence(c)&&isLeftAssociative(c)){
                postfix[j++]=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()){
        postfix[j++]=s.top();
        s.pop();
    }
}

int main(){
    char infix[100];
    char postfix[100];

    cin>>infix;

    infixToPostfix(infix, postfix);

    cout<<postfix<<"\n";
    
    return 0;
}
