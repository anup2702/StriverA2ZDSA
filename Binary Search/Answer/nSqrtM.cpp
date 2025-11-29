class Solution {
public:
    int NthRoot(int N, int M) {
        int l = 1, r = M;
        
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            long long val = power(mid, N, M);

            if(val == 1) return mid;  // exact root
            else if(val == 2) r = mid - 1; // mid^N too large
            else l = mid + 1;              // mid^N too small
        }
        
        return -1;  // no integer root
    }

    long long power(long long mid, int N, int M) {
        long long ans = 1;
        for(int i = 1; i <= N; i++) {
            ans *= mid;
            if(ans > M) return 2;     // too large
        }
        if(ans == M) return 1;        // exact match
        return 0;                     // too small
    }
};
