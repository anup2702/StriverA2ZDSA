class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0, mxlen = 1;

        // treat each index as a center
        for(int i=0; i<n; i++){
            // j=0 odd, j=1 even
            for(int j=0; j<=1; j++){
                int l=i, h=i+j;
                while(l>=0 and h<n and s[l]==s[h]){
                    int currlen = h-l+1;
                    if(currlen > mxlen){
                        mxlen = currlen;
                        st = l;
                    }
                    l--;
                    h++;
                }
            }
        }
        return s.substr(st,mxlen);
    }
};

// tc - n^2 sc - 1