class Solution {
public:
    int myAtoiHelper(const string &s, int i, int sign, int res) {
        if (i >= s.size() || !isdigit(s[i])) {
            return sign * res;
        }
        int digit = s[i] - '0';

        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;
        return myAtoiHelper(s, i + 1, sign, res);
    }

    int myAtoi(string s) {
        int i = 0; 
        int sign = 1; 

        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return myAtoiHelper(s, i, sign, 0);
    }
};
