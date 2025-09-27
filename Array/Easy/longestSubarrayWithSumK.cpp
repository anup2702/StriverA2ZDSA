class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int prefixSum = 0, n = arr.size(), len = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            if(prefixSum == k) len = i + 1;
            else if(mp.find(prefixSum-k) != mp.end()){
                len = max(len, i - mp[prefixSum-k]);
            }
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }
        }
        return len;
    }
};