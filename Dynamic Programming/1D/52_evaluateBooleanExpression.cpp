
class Solution {
public:
    char evaluate(vector<char> list, char op) {
        if (op == '&') {
            if (find(list, 'f')) return 'f';
            else return 't';
        }
        if (op == '|') {
            if (find(list, 't')) return 't';
            else return 'f';
        }
        if (op == '!') {
            if (list[0] == 'f') return 't';
            else return 'f';
        }
        return ' ';
    }
    
    bool find(vector<char> list, char op) {
        for (char ch: list) {
            if (ch == op) return true;
        }
        return false;
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == ')') {
                vector<char> list;
                char op;
                while (st.top() != '(') {
                    list.push_back(st.top());
                    st.pop();
                }
                st.pop();
                op = st.top();
                st.pop();
                char ans = evaluate(list, op);
                st.push(ans);
            } else {
                if (ch != ',' && ch != '(') {
                    st.push(ch);
                } else if (ch == '(') {
                    st.push(ch);
                }
            }
        }
        return st.top() == 't';
    }
};