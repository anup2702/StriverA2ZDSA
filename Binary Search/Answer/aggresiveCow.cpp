class Solution {
  public:
  
  bool isPossible(vector<int> &stalls, int k, int mid){
      int cowCount = 1;
      int lastPos = stalls[0];
      
      for(int i=1; i<stalls.size(); i++){
          if(stalls[i]-lastPos >= mid){
              cowCount++;
              lastPos = stalls[i];
              if(cowCount == k) return true;
          }
      }
      return false;
  }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls.back() - stalls[0];
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(isPossible(stalls, k, mid)){
                ans = mid;
                low = mid + 1;
            } else{
                high = mid -1;
            }
        }
        return ans;
    }
};