#include <iostream>
#include <cstring> 
#include <stack>
using namespace std;
// For strlen function

// Function to reverse a string in place
void reverseString(char* str) {
    // Type your logic here
    stack<char> s;
    int n = strlen(str);
    for(int i=0;i<n;i++) s.push(str[i]);
    for(int i=0;i<n;i++) 
    {
        str[i]=s.top();
        s.pop();
    }
}

int main() {
    char input[100];
    cin >> input;
    reverseString(input);
    cout << input <<endl;
    return 0;
}