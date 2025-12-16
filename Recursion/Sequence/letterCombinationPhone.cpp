class Solution {
public:

    void solve(int idx, string curr, vector<string>& ans, string& digits, vector<string>& mpp){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        for(char c: mpp[digits[idx]-'0']){
            solve(idx+1, curr + c, ans, digits, mpp);
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string> mpp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
       vector<string> ans;
       string curr = "";
       solve(0, curr, ans, digits, mpp);
       return ans;
    }
};