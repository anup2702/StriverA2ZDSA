class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int k, int m){
        int canMake = 0, cnt = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                canMake += (cnt/k);
                cnt = 0;
            }
        }
        canMake += (cnt/k);
        return canMake >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int h = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = h;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(possible(bloomDay, mid, k, m)) {h = mid -1; ans = mid;}
            else l = mid + 1;
        }
        return ans;
    }
};