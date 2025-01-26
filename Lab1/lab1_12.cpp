#include <iostream>
#include <vector>
using namespace std;

class CharacterMatrix {
private:
    int n;
    char startChar;
    vector<vector<char>> matrix;

public:
    // Constructor to initialize the matrix size and starting character
    CharacterMatrix(int size, char ch) : n(size), startChar(ch) {
        matrix = vector<vector<char>>(n,vector<char>(n,' '));
        // TODO: Initialize the matrix storage
    }
    char nextChar(char current) {
        return current == 'z' ? 'a' : current + 1;
    }
    void generateMatrix() {
        char currentChar = startChar;
        int layers = (n + 1) / 2;  

        for (int layer = 0; layer < layers; layer++) {
            for (int i = layer; i < n - layer; i++) {
                matrix[layer][i] = currentChar;
            }
            for (int i = layer; i < n - layer; i++) {
                matrix[n - layer - 1][i] = currentChar;
            }
            for (int i = layer;i < n - layer; i++) {
                matrix[i][layer] = currentChar;
            }
            for (int i = layer; i < n - layer; i++) {
                matrix[i][n - layer - 1] = currentChar;
            }
            currentChar = nextChar(currentChar);
        }
        // TODO: Implement the logic to generate the matrix
    }

    // Method to print the generated matrix
    void printMatrix() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << matrix[i][j];
            }
            cout << '\n';  
        }
        // TODO: Implement the logic to print the matrix
    }
};

int main() {
    int n;
    char startChar;

    cin >> n;
    cin >> startChar;

    // TODO: Create a CharacterMatrix object
     CharacterMatrix characterMatrix(n, startChar);

    // TODO: Generate and print the character matrix
    characterMatrix.generateMatrix();
    characterMatrix.printMatrix();

    return 0;
}