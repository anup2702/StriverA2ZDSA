class Solution {
public:
    bool isValid(string curr){
        stack<char> st;
        for(char c: curr){
            if(c=='(') st.push(c);
            else{
                if(st.empty()) return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void solve(int n, string curr, vector<string>& ans) {
        if (n == 0) {
            if(isValid(curr)) ans.push_back(curr);
            return;
        }
        solve(n - 1, curr + "((", ans);
        solve(n - 1, curr + "()", ans);
        solve(n - 1, curr + "))", ans);
        solve(n - 1, curr + ")(", ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};