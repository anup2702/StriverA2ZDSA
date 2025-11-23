class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;

        vector<int> lps(t.size(), 0);
        for (int i = 1; i < t.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && t[i] != t[len]) {
                len = lps[len - 1];
            }
            if (t[i] == t[len]) len++;
            lps[i] = len;
        }

        string suffix = s.substr(lps.back());
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};

// suffix of s which is also a prefix of rev(s) is palindrome
// tc - n sc - n