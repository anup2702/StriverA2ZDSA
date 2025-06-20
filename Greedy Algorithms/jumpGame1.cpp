class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIdx) return false; // putofbound
            maxIdx = max(maxIdx,i+nums[i]);
        }
        return true;
    }
};

// max index is the farthest we can reach
// if we reach a point where i > maxIdx, it means we cannot reach this point