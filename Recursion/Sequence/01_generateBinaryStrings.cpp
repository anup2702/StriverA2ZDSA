class Solution {
public:
    void solve(int n, vector<string>& ans, string& curr){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        if(curr.empty() or curr.back() != '1') solve(n, ans, curr + '1');
        solve(n, ans, curr+'0';)
    }
    vector<string> generateBinaryStrings(int n) {
        // Your code goes here
        vector<string> ans;
        solve(n, ans, "");
        return ans;
    }
};
