#include <bits/stdc++.h>

using namespace std;
// Class to handle document editing operations
class DocEditor {
public:
    void processInput() {
        char ch;
        string word = "";
        bool capitalizeNext = true; 
        bool space = false; 

        // Read characters until EOF
        while (cin.get(ch)) {
            if (isSpace(ch)) {
                if (!space) {
                    handleWordBoundary(ch, word, capitalizeNext);
                    cout << " ";
                }
                space = true;
            } else if (isPunctuation(ch)) {
                handleWordBoundary(ch, word, capitalizeNext);
                cout << ch;
                capitalizeNext = true;
                space = false;
            } else {
                if (capitalizeNext && isalpha(ch)) {
                    ch = toupper(ch);
                    capitalizeNext = false;
                } else if (isalpha(ch)) {
                    ch = tolower(ch);
                }
                word += ch;
                space = false;
            }
        }
        handleWordBoundary(' ', word, capitalizeNext);
    }

private:
    // Function to check if the given word is an article
    bool isArticle(const string &word) {
        return (word == "a" || word == "an" || word == "the");
    }

    // Function to print the word, underlining articles with underscores
    void printWord(const string &word, bool &capitalizeNext) {
        string lowerWord = word;
        for (auto &ch : lowerWord) ch = tolower(ch); // Convert word to lowercase for comparison

        if (lowerWord == "school")cout << "garden";
        else if (isArticle(lowerWord)) {
            if (capitalizeNext) {
                cout << "" << (char)toupper(word[0]) << word.substr(1) << ""; // Capitalize article and underline
                capitalizeNext = false;
            } 
            else cout << "_" <<word << "_";
        } 
        else cout <<word;
    }

    // Function to check if a character is a space
    bool isSpace(char ch) {
        return ch == ' ';
    }

    // Function to check if a character is a punctuation mark
    bool isPunctuation(char ch) {
        return ch == '.' || ch == '!' || ch == '?';
    }

    void handleWordBoundary(char ch, string &word, bool &capitalizeNext) {
        if (!word.empty()) {
            printWord(word, capitalizeNext);
            word.clear();
        }
    }
};
int main() {
    DocEditor editor;
    editor.processInput();
    return 0;
}
//3rd