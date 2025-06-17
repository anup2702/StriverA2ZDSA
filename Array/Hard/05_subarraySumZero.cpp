/*You are required to complete this function*/
// ----- s -----
// ---s------0---
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int len = 0, sum = 0;
        unordered_map<int, int>mpp; // prefix sum, index
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum == 0) len = i + 1;
            else{
                if(mpp.find(sum) != mpp.end()){
                    len = max(len, i-mpp[sum]);
                } else {
                    mpp[sum] = i;
                }
            }
        }
        return len;
        
    }
};