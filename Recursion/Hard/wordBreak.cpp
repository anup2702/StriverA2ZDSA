class Solution {
public:
    bool fn(int i, string s, vector<string>& wordDict){
        if(i==s.length()) return true;
        string prefix = "";
        for(int j=i; j<s.length(); j++){
            prefix += s[j];
            if(find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end() and fn(j+1, s, wordDict)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return fn(0, s, wordDict);
    }
};

// s = ilike, wordDict = i like dogs
// i is in dict - true
// l, li, lik - not in dict - false
// like - true



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(string &w: wordDict){
                // where word begin ended at i 
                int st = i - w.size();
                if(st>=0 and dp[st] and s.substr(st, w.size())==w){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


// dp[i] - s[0:i] can be broken into dict word