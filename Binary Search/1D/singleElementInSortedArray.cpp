class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int l = 1, h = n-2;
        while(l<=h){
            int m = (l + h)/2;
            if(nums[m] != nums[m-1] and nums[m] != nums[m+1]) return nums[m];
            // odd even, even odd
            else if((m%2 == 1 and nums[m-1] == nums[m]) or (m%2 == 0 and nums[m] == nums[m+1])) l = m + 1;
            else h = m - 1;
        }
        return -1;
    }
};