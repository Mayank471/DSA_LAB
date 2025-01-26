#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // For std::reverse

using namespace std;

class KDigitsRemover {
public:
    // Constructor to initialize the number and the count of digits to remove
    KDigitsRemover(const string& number, int removeCount)
        : num(number), k(removeCount) {}

    // Public method to perform the removal of k digits
    string removeKdigits() {
        stack<char> s;

        for(char digit:num){
            while(!s.empty()&&s.top()>digit&&k>0){
                s.pop();
                k--;
            }
            s.push(digit);
        }
        while (k>0&&!s.empty()) {
            s.pop();
            k--;
        }
        string result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        while (!result.empty() && result[0] == '0') {
            result.erase(result.begin());
        }
        return result.empty() ? "0" : result;
    }

private:
    string num; // Number as a string
    int k;      // Number of digits to remove
};

int main() {
    string num;
    int k;

    // Input handling
    cin >> num;
    cin >> k;

    // Create an instance of KDigitsRemover
    KDigitsRemover remover(num, k);

    // Call the method to get the smallest number
    string smallestNumber = remover.removeKdigits();

    // Output the result
    cout << smallestNumber << endl;

    return 0;
}
