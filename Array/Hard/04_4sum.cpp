class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long rem = (long long)target - nums[i] - nums[j];

                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long sumLR = nums[l] + nums[r];

                    if (sumLR == rem) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sumLR < rem) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }
        return res;
    }
};

// n^3