class Solution {
public:
    int longestBitonicSequence(int n, vector<int> &nums) {

        vector<int> a(n, 1), b(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && a[i] < a[j] + 1)
                    a[i] = a[j] + 1;
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j > i; j--){
                if(nums[i] > nums[j] && b[i] < b[j] + 1)
                    b[i] = b[j] + 1;
            }
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(a[i]>1 and b[i]>1) maxi = max(maxi, a[i] + b[i] - 1);
        }

        return maxi;
    }
};
