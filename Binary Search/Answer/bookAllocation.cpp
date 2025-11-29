class Solution {
  public:
    int cntStu(vector<int>& arr, int pages){
        int stu = 1, pagesStu = 0;
        for(int i=0; i<arr.size(); i++){
            if(pagesStu + arr[i] <= pages) pagesStu += arr[i];
            else{
                stu++;
                pagesStu = arr[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        
        while(l<=h){
            int m = l + (h-l)/2;
            int stu = cntStu(arr, m);
            if(stu > k) l = m + 1; 
            else h = m - 1;
        }
        return l;
    }
};

// maxEl -> covers all the pages
// a student can holds all pages