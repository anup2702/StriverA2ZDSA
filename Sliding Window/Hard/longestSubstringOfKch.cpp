class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int i = 0, j = 0, n = s.size();
        unordered_map<char, int> mp;
        int mx = -1;

        while (j < n) {
            mp[s[j]]++;
            if(mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            if(mp.size() == k) {
                mx = max(mx, j - i + 1);
            }

            j++;
        }

        return mx;
    }
};