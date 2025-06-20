// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int t=0,wt=0;
        for(int i=0;i<bt.size();i++){
            wt += t;
            t += bt[i];
        }
        return wt/bt.size();
    }
};