class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefixSum = 1, suffixSum = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(!prefixSum) prefixSum = 1; // 0 it means multiplied with 0, so reset to 1
            if(!suffixSum) suffixSum = 1;

            prefixSum *= nums[i];
            suffixSum *= nums[n-i-1];

            ans = max(max(prefixSum, suffixSum), ans);
        }
        return ans;
    }
};