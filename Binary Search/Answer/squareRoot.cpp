// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        long long s=0,e=n;
        long long ans=0;
        while(s<=e) {
            long long mid = s+(e-s)/2;
            if(mid*mid == n) return mid;
            else if(mid*mid < n){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};