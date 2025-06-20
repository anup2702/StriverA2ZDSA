
// O(n)
// maintain a range of reachable indices

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0, l =0, r= 0;
        while(r < n-1){
            int far = 0;
            // for every range calculate the farthest reachable index
            for(int i = l; i<= r; i++){
                far = max(far, i+nums[i]);
            }
            l = r + 1;
            r = far;
            jump++;
        }
        return jump;
    }
};