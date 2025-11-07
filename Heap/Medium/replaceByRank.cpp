// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> ans(N);
        // element + original idx
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        int pos = 0;
        for(int el: arr){
            pq.push({el, pos});
            pos++;
        }
        
        int rank = 1;
        int prev = -1e9;
        while(!pq.empty()){
            auto [val, idx] = pq.top();
            pq.pop();
            
            if(val != prev){
                prev = val;
                ans[idx] = rank;
                rank++;
            } else{
                ans[idx] = rank-1;
            }
        }
        return ans;
    }
};
