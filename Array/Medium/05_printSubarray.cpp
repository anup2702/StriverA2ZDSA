// Max Subarray Sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, maxi = INT_MIN;
        // st = 0, ansSt = -1, andEnd = -1;

        for(int i=0;i<nums.size();i++){
            // if(sum == 0) st = i;
            sum += nums[i];
            if(sum > maxi) maxi = max(maxi, sum); // ansSt = st, ansEnd = i;
            if(sum <0) sum = 0;
        }

        return maxi;
    }
};