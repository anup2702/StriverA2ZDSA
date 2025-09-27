#include <bits/stdc++.h>
using namespace std;

void bubbleSortRecursive(vector<int>& arr, int n) {
    // Base case
    if (n == 1) return;

    // One pass of Bubble Sort (largest element moves to end)
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for remaining array
    bubbleSortRecursive(arr, n - 1);
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSortRecursive(arr, arr.size());
    for (int x : arr) cout << x << " ";
    return 0;
}
