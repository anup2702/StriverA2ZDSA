class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans;
        
        // already negative, that means you’ve seen el before → el is repeating
        for(int i=0; i<n; i++){
            int el = abs(arr[i]);
            if(arr[el-1] < 0) ans.push_back(el);
            else arr[el-1] *= -1;
        }
        // If a number x was never visited, its index x-1 will remain positive.
        //     So i+1 is the missing number.
        for(int i=0; i<n; i++){
            if(arr[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};