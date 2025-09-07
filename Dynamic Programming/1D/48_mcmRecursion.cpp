class Solution {
  public:
  
  int fn(vector<int> &arr, int i, int j){
      if(i==j) return 0;
      int mini = INT_MAX;
      for(int k=i; k<j; k++){
          int ans = fn(arr, i, k) + fn(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
          mini = min(mini, ans);
      }
      return mini;
  }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int i=1, j=arr.size()-1;
        return fn(arr, i, j);
        
    }
};