#include <iostream>

const int N = 3; // Assuming a 3x3 matrix for this example

void rotateImage(int matrix[N][N]) {
    // Transpose the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < N; ++i) {
        int start = 0, end = N - 1;
        while (start < end) {
            std::swap(matrix[i][start], matrix[i][end]);
            ++start;
            --end;
        }
    }
}

// Example usage:
int main() {
    int matrix[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::cout << "Original Matrix:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    rotateImage(matrix);

    std::cout << "\nRotated Matrix:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
