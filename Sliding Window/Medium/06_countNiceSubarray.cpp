class Solution {
public:
     int totalSubarray(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0, r=0, cnt = 0, sum =0, n = nums.size();
        while(r<n){
            sum += (nums[r]%2);
            while(sum > goal){
                sum -= (nums[l] % 2);
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return totalSubarray(nums, k)-totalSubarray(nums, k-1); // <= k and <= k-1 diff is K
    }
};