class Solution {

private:
    vector<string> res;
    string s;
    long long tar;

    void fn(int idx, long long prevOp, long long curVal, string exp){
        if(idx == s.size()){
            if(curVal == tar) res.push_back(exp);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(i != idx && s[idx] == '0') break;

            string curStr = s.substr(idx, i - idx + 1);
            long long curNum = stoll(curStr);

            if(idx == 0){
                fn(i+1, curNum, curNum, curStr);
            } else {
                fn(i+1, curNum, curVal + curNum, exp + '+' + curStr);
                fn(i+1, -curNum, curVal - curNum, exp + '-' + curStr);
                fn(i+1,
                   prevOp * curNum,
                   curVal - prevOp + prevOp * curNum,
                   exp + '*' + curStr);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        res.clear();
        s = num;
        tar = target;   
        fn(0, 0, 0, "");
        return res;
    }
};
