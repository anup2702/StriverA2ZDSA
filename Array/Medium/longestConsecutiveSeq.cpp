class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int longest = INT_MIN;
        unordered_set<int> st;
        for(int i=0; i<n; i++) st.insert(nums[i]);
        for(auto it: st){
            if(st.find(it-1) == st.end()){ // if prev not found, st. point
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){ // next found
                    x +=1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;

    }
};