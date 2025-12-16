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



class Solution {
public:
    vector<int> replaceWithRank(vector<int> &arr, int N) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for (int i = 0; i < N; i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = rank;
                rank++;
            }
        }
        for (int i = 0; i < N; i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};


// nlogn, n