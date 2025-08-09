// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size(), m = pat.size();
        if(m > n) return -1;
        
        const int base = 256, mod = 1e9 + 7; // base - ascii ch. 
        
        // power of rolling hash
        long long h = 1;
        for(int i=0; i<m-1; i++){
            h = (h * base) % mod;
        }
        
        long long patHash = 0, textHash = 0;
        for(int i=0; i<m; i++){
            patHash = (patHash * base + pat[i]) % mod;
            textHash = (textHash * base + text[i]) % mod;
        }
        
        for(int i=0; i<= n-m; i++){
            if(patHash == textHash){
                if(text.substr(i, m) == pat) return i;
            }
            if(i < n-m){
                textHash = (textHash - text[i] * h) % mod;
                textHash = (textHash * base + text[i+m]) % mod;
                
                if(textHash < 0) textHash += mod;
            }
        }
        return -1;
    }
};


// n+m