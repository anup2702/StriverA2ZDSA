class Solution {
public:
    void fn(int idx, string s, vector<vector<string>>& res,
            vector<string>& path) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                fn(i + 1, s, res, path); 
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int st, int end) {
        while (st <= end) {
            if (s[st++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        fn(0, s, res, path);
        return res;
    }
};
