class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = ""; 
        int counter = 0; 

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') counter--;
            if( counter != 0) result += s[i];
            if (s[i] == '(') counter++;
        }

        return result;
    }
};


// if cnt == 0 not update 
// if cnt - 1 == 0 also not update ans 