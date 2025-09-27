class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(intervals[i][1] >= newInterval[0]){
                newInterval[0] = intervals[i][0];
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            else ans.push_back({intervals[i][0], intervals[i][1]});
        }
        return ans;
    }
};