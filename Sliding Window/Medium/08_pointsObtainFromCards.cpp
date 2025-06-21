class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }

        if(k==n) return sum;
        int maxSum = sum;
        int l = k-1, r = n-1;
        while(l>=0){
            sum -= arr[l];
            l--;
            sum += arr[r];
            r--;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};