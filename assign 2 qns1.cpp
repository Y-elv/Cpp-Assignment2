#include <iostream>
#include <vector>

bool isMagicSquare(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    
    // Calculate the sum of the first row (this will be our reference sum)
    int referenceSum = 0;
    for (int j = 0; j < n; ++j) {
        referenceSum += matrix[0][j];
    }

    // Check the sum of each row and column
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        int colSum = 0;

        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }

        if (rowSum != referenceSum || colSum != referenceSum) {
            return false;
        }
    }

    // Check the sum of the main diagonal
    int mainDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        mainDiagonalSum += matrix[i][i];
    }
    if (mainDiagonalSum != referenceSum) {
        return false;
    }

    // Check the sum of the secondary diagonal
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; ++i) {
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }
    if (secondaryDiagonalSum != referenceSum) {
        return false;
    }

    // If all checks passed, the matrix is a magic square
    return true;
}

int main() {
    // Example usage:
    std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };

    bool result = isMagicSquare(matrix);
    if (result) {
        std::cout << "The matrix is a magic square." << std::endl;
    } else {
        std::cout << "The matrix is not a magic square." << std::endl;
    }

    return 0;
}