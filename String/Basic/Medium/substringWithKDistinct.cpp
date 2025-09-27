class Solution {
  public:
  int count(string& s, int k){
        int n = s.size();
        vector<int> freq(26, 0);
        int distinct = 0, ans = 0, i=0, j=0;
        while(j < n){
            freq[s[j]-'a']++;
            if(freq[s[j]-'a'] == 1) distinct++;
            while(distinct > k){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a'] == 0) distinct--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
  }
    int countSubstr(string& s, int k) {
        // code here
        return count(s, k) - count(s, k-1);
    }
};