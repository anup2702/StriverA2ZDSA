class Solution {
  public:
  long long int gcd(long long int x, long long int y){
      while(x >0 && y>0){
          if(x>y) x %= y;
          else y %= x;
      }
      if(x==0) return y;
      else return x;
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long int res = gcd(A,B);
        long long int lcm = (A/res)*B;
        return {lcm,res};
    }
};


// gcd(a, b) == gcd(b, a % b) for positive integers.

// This property works because if d divides both a and b, it also divides their difference and remainder.