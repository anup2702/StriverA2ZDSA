class Solution {
  public:
  
    static bool comp(pair<int,int> a, pair<int,int> b) {
        double r1 = (double)a.first / (double)a.second;
        double r2 = (double)b.first / (double)b.second;
        return r1 > r2; 
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int c) {
        int n = val.size();
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({val[i], wt[i]});
        }

        sort(arr.begin(), arr.end(), comp);

        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            int v = arr[i].first;
            int w = arr[i].second;

            if (w <= c) {
                ans += v;
                c -= w;
            } else {
                ans += (double)v / w * c;
                break;
            }
        }
        return ans;
    }
};
