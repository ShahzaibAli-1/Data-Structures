#include <iostream>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inversionCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If arr[i] > arr[j], it means there is an inversion
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the merged elements back to the original array
    for (i = left; i <= right; ++i) {
        arr[i] = temp[i];
    }

    return inversionCount;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inversionCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively count inversions in the left and right subarrays
        inversionCount += mergeSortAndCount(arr, temp, left, mid);
        inversionCount += mergeSortAndCount(arr, temp, mid + 1, right);

        // Merge the two sorted subarrays and count inversions
        inversionCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversionCount;
}

long long countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

// Example usage:
int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Inversion Count: " << countInversions(arr, n) << std::endl;

    return 0;
}
