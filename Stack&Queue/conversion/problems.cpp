#include <bits/stdc++.h>
using namespace std;

// Helper: precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Helper: check if operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// 1️⃣ Infix → Postfix
string infixToPostfix(const string &infix) {
    stack<char> st;
    string res;
    for(char c : infix){
        if(isalnum(c)) res += c;
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top(); st.pop();
            }
            st.pop(); // pop '('
        } else { // operator
            while(!st.empty() && precedence(st.top()) >= precedence(c)){
                res += st.top(); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()) { res += st.top(); st.pop(); }
    return res;
}

// 2️⃣ Infix → Prefix
string infixToPrefix(const string &infix) {
    string rev = infix;
    reverse(rev.begin(), rev.end());
    // Swap '(' and ')'
    for(char &c : rev){
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
    string post = infixToPostfix(rev);
    reverse(post.begin(), post.end());
    return post;
}

// 3️⃣ Postfix → Infix
string postfixToInfix(const string &postfix) {
    stack<string> st;
    for(char c : postfix){
        if(isalnum(c)) st.push(string(1,c));
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

// 4️⃣ Prefix → Infix
string prefixToInfix(const string &prefix) {
    stack<string> st;
    for(int i = prefix.size()-1; i >=0; i--){
        char c = prefix[i];
        if(isalnum(c)) st.push(string(1,c));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    return st.top();
}

// 5️⃣ Postfix → Prefix
string postfixToPrefix(const string &postfix) {
    stack<string> st;
    for(char c : postfix){
        if(isalnum(c)) st.push(string(1,c));
        else{
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            st.push(c + op1 + op2);
        }
    }
    return st.top();
}

// 6️⃣ Prefix → Postfix
string prefixToPostfix(const string &prefix) {
    stack<string> st;
    for(int i = prefix.size()-1; i>=0; i--){
        char c = prefix[i];
        if(isalnum(c)) st.push(string(1,c));
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            st.push(op1 + op2 + c);
        }
    }
    return st.top();
}

// 🔹 Test
int main() {
    string infix = "((A+B)*(C-D)/(E^F))+(G*(H-I)+J)";
    cout << "Infix: " << infix << endl;
    
    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    cout << "Postfix → Infix: " << postfixToInfix(postfix) << endl;
    cout << "Prefix → Infix: " << prefixToInfix(prefix) << endl;

    cout << "Postfix → Prefix: " << postfixToPrefix(postfix) << endl;
    cout << "Prefix → Postfix: " << prefixToPostfix(prefix) << endl;

    return 0;
}

