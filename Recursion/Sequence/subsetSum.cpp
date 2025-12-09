class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int n){
        if(n == 0) return false;
        if(sum == 0) return true;
        if(arr[n-1] > sum) return solve(arr, sum, n-1);
        return solve(arr, sum, n-1) or solve(arr, sum - arr[n-1], n-1);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return solve(arr, sum, arr.size());
    }
};