class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);

        int l=0, r=0, maxLen = 0;
        while(r<n){
            // If the character is already in the current substring
            if(hash[s[r]] != -1 && hash[s[r]] >= l){
                l = hash[s[r]] +1;
            }
            maxLen = max(maxLen, r-l+1);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};