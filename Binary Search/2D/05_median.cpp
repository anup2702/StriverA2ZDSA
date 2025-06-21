// upperBound() returns how many elements in a row are less than or equal to x.

// SmallerEqual() uses this to count how many elements in the full matrix are <= x.

// Then, binary search is used on the value range to find the median.

class Solution {
    
    int upperBound(vector<int>& mat, int x){
        int m = mat.size();
        int low = 0, high = m;
        while(low < high){
            int mid = (low + high)/2;
            if(mat[mid] <= x) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    
    int SmallerEqual(vector<vector<int>> &mat, int x){
        int cnt = 0;
        for(int i = 0; i < mat.size(); i++){
            cnt += upperBound(mat[i], x);
        }
        return cnt;
    }
    
  public:
    int median(vector<vector<int>> &mat) {
        int low = INT_MAX, high = INT_MIN;
        int n = mat.size(), m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int req = (n * m) / 2;
        
        while(low < high){
            int mid = (low + high) / 2;
            int count = SmallerEqual(mat, mid);
            
            if(count <= req)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
