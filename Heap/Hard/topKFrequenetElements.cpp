class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++) freq[nums[i]]++;
        vector<vector<int>>buckets(n+1);

        for(auto &x: freq){
            buckets[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=n; i>=0 && ans.size() < k; i--){
            for(int num: buckets[i]){
                ans.push_back(num);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq; // freq, el
        for(auto &x: freq){
            pq.push({x.second, x.first});
        }

        vector<int> ans;
        while(!pq.empty()){
            if(ans.size()==k) break;
            auto [f, el] = pq.top(); pq.pop();
            ans.push_back(el);
        }
        return ans;

    }
};