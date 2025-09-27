#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Optimization: stop if already sorted
    }
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 2};
    bubbleSort(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
