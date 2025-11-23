class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue; // skips same i
            int l = i+1, r = n -1;
            while(l < r){
                int s = nums[i] + nums[l] + nums[r];
                if(s == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r and nums[l] == nums[l-1]) l++; // skips duplicates
                    while(l < r and nums[r] == nums[r+1]) r--;
                }
                else if(s<0) l++;
                else r--;
            }
        }
        return ans;
    }
};

// Sorting → O(n log n)
// Outer loop → O(n)
// Two pointers → O(n)
// Overall → O(n²)