class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int l = 0, h = n-1;
        while(l < h){
            int m = (l + h)/2;
            if(arr[m] > arr[h]){
                l = m + 1;
            } else h = m;
        }
        return l;
    }
};
