class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> req;
        for(char ch : t){
            req[ch]++;
        }
        int l = 0, minlen = INT_MAX;
        int resl = 0, resr = 0;
        int have = 0, reqCnt = req.size();
        unordered_map<char, int> mpp;
        for(int r=0; r<n; r++){
            char c = s[r];
            mpp[c]++;
            // if ch is req -> available and equal
            if(req.find(c) != req.end() and req[c] == mpp[c]){
                have++;
            }
            // if satisfy
            while(have == reqCnt){
                if((r-l+1) < minlen){
                    resl= l; resr = r; minlen = r-l+1;
                }
                char leftel = s[l];
                mpp[leftel]--;
                // if removing left voilates condition
                if(req.find(leftel) != req.end() and mpp[leftel] < req[leftel]) have--;
                l++;
            }
        }
        return (minlen == INT_MAX)? "": s.substr(resl, minlen);
    }
};