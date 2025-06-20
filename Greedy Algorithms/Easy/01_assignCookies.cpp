class Solution {
public:
    int findContentChildren(vector<int>& g,vector<int>& s) {
        if (s.empty()) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int M = 0;
        int i = 0; 
        int j = 0; 

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                M++;
                i++;
            }
            j++;
        }

        return M;
    }
};