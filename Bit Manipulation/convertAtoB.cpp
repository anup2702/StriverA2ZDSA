class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans = start ^ goal;
        int cnt =0;
        while(ans){
            cnt += ans & 1; // cnt set bits
            ans >>= 1; // right shift the bit
        }
        return cnt;
    }
};