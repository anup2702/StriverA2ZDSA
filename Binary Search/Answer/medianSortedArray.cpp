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

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int t = n + m;

        if (t % 2 == 1) {
            return kthElement(a, b, t / 2 + 1);
        }

            int left = kthElement(a, b, t / 2);
            int right = kthElement(a, b, t / 2 + 1);
            return (left + right) / 2.0;
    }

};