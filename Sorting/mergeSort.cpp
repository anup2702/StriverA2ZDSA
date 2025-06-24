class Solution {
    
     void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1;

        while(left <= mid and right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
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
    }
  public:
    void mergeSort(vector<int>& nums, int low, int high){
        if(low >= high) return;
        int mid = (low + high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums,low, mid, high);
    }
};