// O(N log N + C log N)

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n= A.size();
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    priority_queue<vector<int>> pq;
    set<pair<int, int>> vis;
    pq.push({A[0]+B[0], 0, 0});
    vis.insert({0, 0});
    vector<int> ans;
    while(C--){
        auto top = pq.top(); pq.pop();
        int sum = top[0], i=top[1], j=top[2];
        ans.push_back(sum);
        if(i+1 < n and !vis.count({i+1, j})){
            pq.push({A[i+1]+B[j], i+1, j});
            vis.insert({i+1, j});
        }
        if(j+1 < n and !vis.count({i, j+1})){
            pq.push({A[i]+B[j+1], i, j+1});
            vis.insert({i, j+1});
        }
    }
    return ans;
}


// O(N² log C)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap
    
    for (int a : A) {
        for (int b : B) {
            int sum = a + b;
            pq.push(sum);

            if (pq.size() > C) 
                pq.pop(); 
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    sort(ans.rbegin(), ans.rend()); 
    return ans;
}
