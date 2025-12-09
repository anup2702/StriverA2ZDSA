class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> d(n, 1), p(n, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0 and d[i] < d[j]+1){
                    d[i] = d[j]+1;
                    p[i] = j;
                }
            }
        }
        int ans = d[0], pos = 0;
        for(int i=1; i<n; i++){
            if(d[i]>ans){
                ans = d[i]; pos = i;
            }
        }
        vector<int> res;
        while(pos != -1){
            res.push_back(nums[pos]);
            pos = p[pos];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};