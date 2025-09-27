class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        unordered_set<int> c;  
        vector<int> r; 
        int f = 0;

        for(int i = 0; i < N; i++) {
            int p = pages[i];

            if(c.find(p) != c.end()) {
                r.erase(find(r.begin(), r.end(), p));
                r.push_back(p);
            }
            else {
                f++;
                if((int)c.size() == C) {
                    int old = r.front();
                    r.erase(r.begin());
                    c.erase(old);
                }
                c.insert(p);
                r.push_back(p);
            }
        }
        return f;
    }
};
