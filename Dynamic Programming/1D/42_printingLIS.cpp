class Solution {
  public:
    vector<int> getLIS(vector<int>& nums) {
        // Code here
        int n = nums.size();
        vector<int> d(n, 1), p(n+1, -1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j] and d[i] < d[j]+1){
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