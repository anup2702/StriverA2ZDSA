class Solution {
  public:
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int, int>> job;
        for(int i=0; i<n; i++){
            job.push_back({deadline[i], profit[i]});
        }
        sort(job.begin(), job.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++){
            pq.push(job[i].second);
            if(pq.size() > job[i].first){
                pq.pop();
            }
        }
        
        int p = 0, cnt = pq.size();
        while(!pq.empty()){
            p += pq.top();
            pq.pop();
        }
        return {cnt, p};
    }
};