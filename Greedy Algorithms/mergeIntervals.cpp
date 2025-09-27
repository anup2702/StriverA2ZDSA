class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) { 
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);

        vector<vector<int>> ans;
        vector<int> inte = intervals[0];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= inte[1]) { 
                inte[1] = max(inte[1], intervals[i][1]);
            } else {
                ans.push_back(inte);
                inte = intervals[i];
            }
        }
        ans.push_back(inte);
        return ans;
    }
};
