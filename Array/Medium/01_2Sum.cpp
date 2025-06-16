class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int req = target - a;
            if(mpp.find(req) != mpp.end()){
                return {mpp[req],i};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};