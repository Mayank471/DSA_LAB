#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<char>> convertTo2DArray(const string& str) {
    // Your code here
    vector<string> all_word;
    int max_len = 0;
    string word;
    for (char ch : str) {
        if (ch == ' ') {
            if (!word.empty()) {
                all_word.push_back(word);
                max_len = max(max_len, (int)word.length());
                word.clear(); 
            }
        } else {
            word += ch;
        }
    }
    if (!word.empty()) {
        all_word.push_back(word);
        max_len = max(max_len, (int)word.length());
    }
    vector<vector<char>> result;
    for (const string& w : all_word) {
        vector<char> row(max_len, ' ');
        for (size_t i = 0; i < w.length(); i++) {
            row[i] = w[i];
        }
        result.push_back(row);
    }

    return result;
}

int main() {
    string input;
    getline(cin, input); 

    // Convert the input string to a 2D matrix
    vector<vector<char>> result = convertTo2DArray(input);

    // Print the matrix
    for (const auto& row : result) {
        cout << "[";
        for (size_t j = 0; j < row.size(); j++) {
            cout << "'" << row[j] << "' ";
        }
        cout << "]" << endl;
    }

    return 0;
}
