class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, n = s.size(), cnt = 0, freq[3] = {0};

        while (r < n) {
            freq[s[r] - 'a']++;
            while (freq[0] > 0 and freq[1] > 0 and freq[2] > 0) {
                cnt += n - r;
                freq[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};