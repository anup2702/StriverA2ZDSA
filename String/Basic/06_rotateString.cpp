class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            char first = s[0];
            s.erase(0, 1); // Remove first char
            s.push_back(first); // Append it at the end
            
            if (s == goal) return true;
        }
        
        return false; 
    }
};

/*
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
*/
