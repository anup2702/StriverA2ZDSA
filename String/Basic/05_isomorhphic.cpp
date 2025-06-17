class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int mapS[256] = {0}; // s->t
        int mapT[256] = {0};  // t->s

        for (int i = 0; i < s.length(); ++i) {
            char cs = s[i];
            char ct = t[i];

            // if already map
            if (mapS[cs] != mapT[ct]) return false;
            // Keep track of marked
            mapS[cs] = i + 1;
            mapT[ct] = i + 1;
        }

        return true;
    }
};
