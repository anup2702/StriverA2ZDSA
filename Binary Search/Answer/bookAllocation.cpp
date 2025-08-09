class Solution {
  public:
  int cntStu(vector<int>& arr, int pages){
      int stu = 1;
      long long pageStu = 0;
      for(int i=0; i<arr.size(); i++){
          if(arr[i] + pageStu <= pages) pageStu += arr[i];
          else{
              stu++;
              pageStu = arr[i];
          }
      }
      return stu;
  }
  
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            int mid = (low + high)/2;
            int stu = cntStu(arr, mid);
            if(stu > k) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};