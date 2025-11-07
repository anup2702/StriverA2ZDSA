// O(n*m) forward and backward shrink
class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int i=0, j=0, stIdx = -1, minlen = INT_MAX;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                j++;
                if(j== s2.size()){
                    int end = i;
                    j--;
                    while(j >= 0){
                        if(s1[i] == s2[j]) j--;
                        i--;
                    }
                    i++;
                    j++;
                    
                    int len = end - i +1;
                    if(len < minlen){
                        minlen = len;
                        stIdx = i;
                    }
                }
            }
            i++;
        }
        return (stIdx == -1) ? "": s1.substr(stIdx, minlen);
        
    }
};
