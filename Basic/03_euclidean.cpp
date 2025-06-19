// if a > b
// gcd(a, b) = gcd(a-b, b);
// if one of the numbers is zero, the other number is the gcd.

long long int gcd(long long int x, long long int y){
      while(x >0 && y>0){
          if(x>y) x %= y;
          else y %= x;
      }
      if(x==0) return y;
      else return x;
  }