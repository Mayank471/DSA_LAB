#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    int n;
    vector<vector<int>> matrix;

public:
    // Constructor to initialize the matrix size
    SquareMatrix(int size) : n(size), matrix(size, vector<int>(size)) {}

    // Method to input matrix elements
    void inputMatrix() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    // Method to print the lower triangular matrix
    void printLowerTriangularMatrix() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > j) {
                    cout << matrix[i][j] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    // Create a SquareMatrix object
    SquareMatrix matrix(n);

    // Input matrix elements
    matrix.inputMatrix();

    // Print the lower triangular matrix
    matrix.printLowerTriangularMatrix();

    return 0;
}
