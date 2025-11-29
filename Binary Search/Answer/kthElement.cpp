class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size(), m = b.size(), i=0, j=0;
        while(i<n and j<m){
            if(a[i]<b[j]){
                if(k==1) return a[i];
                k--;
                i++;
            } else{
                if(k==1) return b[j];
                k--;
                j++;
            }
        }
        while(i<n){
            if(k==1) return a[i];
            k--;
            i++;
        }
        while(j<m){
            if(k==1) return b[j];
            k--;
            j++;
        }
        return -1;
    }
};