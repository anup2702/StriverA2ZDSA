class TrieNode {
public:
    TrieNode* children[26];
    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    int countSubs(string& s) {
        TrieNode* root = new TrieNode();
        int cnt = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            TrieNode* node = root;
            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if(node->children[idx] == nullptr) { // not present
                    node->children[idx] = new TrieNode();
                    cnt++;
                }
                node = node->children[idx];
            }
        }
        return cnt;
    }
};
