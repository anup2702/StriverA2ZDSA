class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<double> gaps(n-1);
        double l = 0, h = 0;
        for(int i=0; i<n-1; i++){
            gaps[i] = stations[i+1] - stations[i];
            h = max(h, gaps[i]);
        }
        while(h-l > 1e-6){ // stop when diff is almost same
            double m = (l + h)/2.0;
            int needed = 0;
            for(double gap: gaps){
                needed += (int)gap/m;
            }
            if(needed <= k) h = m;
            else l = m;
        }
        return l;
        
    }
};