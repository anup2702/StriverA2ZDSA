class Solution {
public:
    int solve(vector<int>& arr, int i, int current_sum, int k) {
        if (i == arr.size()) {
            return (current_sum == k);
        }

        // exclude element
        int not_take = solve(arr, i + 1, current_sum, k);

        // include element
        int take = solve(arr, i + 1, current_sum + arr[i], k);

        return take + not_take;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        return solve(nums, 0, 0, k);
    }
};
