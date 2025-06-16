class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int seclargest = -1, largest = arr[0];
        for(int i=1; i < arr.size(); i++){
            if(arr[i] > largest){
                seclargest = largest;
                largest = arr[i];
            }
            if(arr[i] > seclargest && arr[i] != largest){
                seclargest = arr[i];
            }
        }
        return seclargest;
        
    }
};