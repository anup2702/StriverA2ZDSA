// Reverse the whole sentence, 
// Extract each word and reverse and store in res

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();

        string res = "";
        for(int i = 0; i < n; i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0) res += " " + word;
        }

        return res.substr(1);
    }
};