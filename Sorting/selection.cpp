class Solution
{
    public:
    // if it finds a smaller element, it swaps it with the current element
    // Time Complexity: O(n^2)
     
     void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=0;i<n;i++){
           int m=i;
           
           for(int j=i+1;j<n;j++){
               if(arr[j]<arr[m]){
                   m=j;
               }
           }
           
           if(arr[m]<arr[i]) swap(arr[i],arr[m]);
       }
    }
};