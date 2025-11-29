class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = INT_MAX;
        while(l <= r){
            int m = l + (r-l)/2;
            int val = 0;
            for(auto it: nums){
                val += it/m + (it%m!=0);
            }
            if(val <= threshold) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};