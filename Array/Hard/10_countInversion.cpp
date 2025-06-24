class Solution {

    int merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;

        int cnt = 0;
        while(left <= mid and right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            } else { // left is greater
                temp.push_back(nums[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        
        for(int i = low; i <= high; ++i){
            nums[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high)/2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += merge(nums,low, mid, high);
        return cnt;
    }
public:  
    int inversionCount(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};