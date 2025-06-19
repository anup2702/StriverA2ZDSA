// sort the strs and compare first and last string

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());

        string res = "";
        string first = strs[0], last = strs[n-1];
        for(int i = 0; i<first.size(); i++){
            if(first[i] == last[i]) res += first[i];
            else break;
        }
        return res;
    }
};