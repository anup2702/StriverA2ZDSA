class Solution {
public:
    double helper(double x, long long n) {
        if(n == 0) return 1;
        double half = helper(x, n / 2);
        if(n % 2 == 0) return half * half;
        else return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        return helper(x, N);
    }
};
