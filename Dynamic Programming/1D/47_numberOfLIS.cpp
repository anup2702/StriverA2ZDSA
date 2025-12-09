class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n, 1), cnt(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && a[i] < a[j] + 1){ // new - inherit
                    a[i] = a[j] + 1;
                    cnt[i] = cnt[j];
                } else if(nums[i] > nums[j] && a[i] == a[j] + 1){ // got someone with same length
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi, a[i]);
        }

        int cntt = 0;
        for(int i=0; i<n; i++){
            if(a[i]==maxi) cntt += cnt[i];
        }
        return cntt;
    }
};