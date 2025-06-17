class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int neg = 1, pos = 0;
        vector<int> ans(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            if(nums[i] <0){
                ans[neg] = nums[i];
                neg += 2;
            }
            else{
                ans[pos] = nums[i];
                pos += 2;
            }
        }

        return ans;
    }
};


// No of +ve and -ve are not equal

// Approach
// 1. Create pos and neg array
// 2. Traverse till minSize of pos and neg and store the ans.
//  ans[2i] = pos, ans[2i+1] = neg
// Iterate the remaining elements of pos or neg and store them in ans.