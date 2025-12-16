class Solution {
public:

    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds, int k) {
        if(ind == 10) return;
        if (ds.size() == k) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind + 1, target - arr[ind], arr, ans, ds, k);
            ds.pop_back();
        }

        findCombination(ind + 1, target, arr, ans, ds, k); // not pick
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(10);
        for(int i=0; i<10; i++) arr[i] = i+1;
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, n, arr, ans, ds, k);
        return ans;
    }
};