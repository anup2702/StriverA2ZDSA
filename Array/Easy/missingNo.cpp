class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1=0,x2=0;
        for(int i=0;i<nums.size();i++){
            x2 = x2^nums[i];
            x1 = x1^i;
        }
        x1 = x1^nums.size();

        return x1^x2;
    }
};