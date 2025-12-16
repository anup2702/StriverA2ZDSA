class Solution {
  public:
    int minCost(vector<int>& sticks) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: sticks){
            pq.push(num);
        }
        int total = 0;
        while(pq.size()>1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int cost = a+b;
            total += cost;
            pq.push(cost);
        }
        return total;
    }
};