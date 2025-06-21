class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; // low (, high )
        for (char ch : s) {
            if (ch == '(') {
                low++; high++;
            } else if (ch == ')') {
                low--; high--;
            } else { // '*'
                low--; high++;
            }

            if (high < 0) return false; // too many ')'

            if (low < 0) low = 0; // '*' used as '(' or empty
        }
        return low == 0;
    }
};
