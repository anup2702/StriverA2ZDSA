// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long> ans;
        long long fact=1,i=1;
        while(fact<=n)
        {
            ans.push_back(fact);
            i++;
            fact*=i;
        }
        return ans;
    }
};