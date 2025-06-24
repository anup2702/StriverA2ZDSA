// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
        return pow(2,n*(n-1)/2);   
    }
};