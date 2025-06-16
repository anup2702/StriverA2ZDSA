// element is leader if it is greater than or equal to all the elements to its right side.
// max of right 

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n = arr.size();
        
        int maxOfRight = INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            if(arr[i] >= maxOfRight){
                ans.push_back(arr[i]);
                maxOfRight = max(maxOfRight, arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};