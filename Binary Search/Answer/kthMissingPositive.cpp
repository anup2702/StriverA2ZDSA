class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    // Write your code here.
    int n = arr.size();
    int low =0,high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        int missing = arr[mid]-(mid +1);
        if(missing < k) low = mid +1;
        else high = mid -1;
    }
    return k+low;
}

};


// if all el presnet, then a[i] = i + 1
// missing is arr[mid] - mid - 1

// k - missing, low - present el