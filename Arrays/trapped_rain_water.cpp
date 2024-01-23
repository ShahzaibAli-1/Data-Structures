#include <iostream>

int trapRainWater(int arr[], int n) {
    if (n <= 2) {
        return 0;  // Not enough bars to trap water
    }

    int leftMax[n], rightMax[n];

    // Compute leftMax array
    leftMax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], arr[i]);
    }

    // Compute rightMax array
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], arr[i]);
    }

    // Calculate trapped water
    int trappedWater = 0;
    for (int i = 0; i < n; ++i) {
        trappedWater += std::min(leftMax[i], rightMax[i]) - arr[i];
    }

    return trappedWater;
}

// Example usage:
int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Trapped Rain Water: " << trapRainWater(arr, n) << std::endl;

    return 0;
}
