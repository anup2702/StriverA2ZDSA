class Solution {
public:
    int totalSubarray(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0, r=0, cnt = 0, sum =0, n = nums.size();
        while(r<n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return totalSubarray(nums, goal)-totalSubarray(nums, goal-1);
    }
};