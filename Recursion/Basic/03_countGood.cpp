#define mod 1000000007
using ll = long long;

ll powerMod(ll b, ll e){
    ll res = 1;
    b = b % mod;
    while(e > 0){
        if(e % 2) res = (res * b) % mod;
        b = (b * b) % mod;
        e = e/2;
    }
    return res;
}

class Solution {
public:
    int countGoodNumbers(long long n) {
        ll oddPos = n / 2;
        ll evenPos = n - oddPos;
        ll oddComb = powerMod(4, oddPos);  // 4 choices for odd positions (1, 3, 7, 9)
        ll evenComb = powerMod(5, evenPos); // 5 choices for even positions (0, 2, 4, 6, 8)
        return (evenComb * oddComb) % mod;
    }
};
