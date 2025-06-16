/*
Sorted Array: A sorted array in non-decreasing order should
 never have nums[i-1] > nums[i].

Rotated Array: If the array is sorted and rotated, 
there can be only one place where the order breaks 
(from a large number to a smaller number). 
This break point is where the rotation occurred.

*/

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int cnt = 0;
        int n = nums.size();

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) cnt++;
        }

        if(nums[n-1] > nums[0]) cnt++;
        
        return cnt<=1;
    }
};