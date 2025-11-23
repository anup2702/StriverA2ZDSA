// generate all permutation, do linear search for the given one, return next
// n! * n 

// stl
// next_permutation(arr.begin(), arr.end());


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        // find breakpoint
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // swap 
        for(int i=n-1; i>idx; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // reverse left
        // for(int i=idx; i<(n-idx)/2; i++){
        //     swap(nums[i], nums[n-idx-i-1]);
        // }

        reverse(nums.begin()+idx+1, nums.end());
    }
};