bool comp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
// sort by end time


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);

        int remove = 0, end = INT_MIN;

        for(int i=0; i<intervals.size(); i++){
            if(end <= intervals[i][0]) end = intervals[i][1];
            else remove++;
        }
        return remove;
    }
};