class Solution {
public:
    int maxDepth(string s) {
        int balance = 0, depth = 0;
        for(char ch: s){
            if(ch == '(') balance++;
            if(ch == ')'){
                depth = max(depth, balance);
                balance--;
            }
        }
        return depth;
    }
};