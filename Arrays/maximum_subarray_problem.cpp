#include <iostream>
#include <climits>

long long maxSubarrayProduct(int arr[], int n) {
    long long max_product = INT_MIN;
    long long current_product = 1;

    for (int i = 0; i < n; ++i) {
        current_product *= arr[i];
        max_product = std::max(max_product, current_product);

        if (current_product == 0) {
            // Reset the product if it becomes zero
            current_product = 1;
        }
    }

    return max_product;
}

// Example usage:
int main() {
    int arr[] = {2, 3, -2, 4, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Maximum Subarray Product: " << maxSubarrayProduct(arr, n) << std::endl;

    return 0;
}
