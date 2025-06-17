// N elements, if 2 el appears more than N/3 then others elemenet appears less than N/3;
// N - 2N/3 = N/3
// nested loop and keep track the ans size which is atmost 2

// Better Approach using Hashmap

/*
    ls[], min = floor(N/3), 
    for(i=0-n-1) 
        mpp[arr[i]]++;
        if(mpp[arr[i]] == min) 
            ls.push_back(arr[i]);
    
*/

// Moores Algo Extended

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 and nums[i] != el2){
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 and nums[i] != el1){
                el2 = nums[i];
                cnt2++;
            } 
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ls;
        cnt1 = 0, cnt2 =0;
        for(int i =0; i< n; i++){
            if(el1 == nums[i]) cnt1++;
            if(el2 == nums[i]) cnt2++;
        }
        if(cnt1++ > n/3) ls.push_back(el1);
        if(cnt2++ > n/3) ls.push_back(el2);

        return ls;
    }
};
