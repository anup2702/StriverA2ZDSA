class Solution {
public:
    void reverse(vector<int>& nums, int st, int end){
        while(st<end){
            swap(nums[st++],nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k==0) return;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};