class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long x = 0;
        for(int num: nums) x ^= num;
        // x & (x-1) - unset the rightmost bit and remaining bits unchanged
        // then ^ - set the rightmost bit and unset remaining bit
        int rightmost = (x & (x-1))^x;
        int b1 = 0, b2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]&rightmost) b1 ^= nums[i]; // isolated bit = 1
            else b2 ^= nums[i]; // = 0
        }
        return {b1,b2};
    }
};