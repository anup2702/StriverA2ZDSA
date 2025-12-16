class Solution {
public:
    void findSubsets(int idx, vector<vector<int>>& ans, vector<int>& nums,  vector<int>& ds){
        ans.push_back(ds);
        for(int i=idx; i<nums.size(); i++){
            if(i>idx and nums[i-1] == nums[i]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, ans, nums, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubsets(0, ans, nums, ds);
        return ans;
    }
};