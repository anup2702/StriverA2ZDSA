class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and k>0 and num[i]-'0' < st.top()-'0'){
                st.pop(); k--;
            }
            st.push(num[i]);
        }

        while(k>0) {
            st.pop(); k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        while(res.size() != 0 and res.back()=='0') res.pop_back();
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};