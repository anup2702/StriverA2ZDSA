class TrieNode{
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
    }

    void insert(string &word){
        TrieNode* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    bool isValidWord(string &word){
        TrieNode* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            node = node->children[idx];
            if(node == nullptr || !node->isEndOfWord)
                return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        TrieNode trie;

        for(auto &w : words) trie.insert(w);

        string longest = "";

        for(auto &w : words){
            if(trie.isValidWord(w)){
                if(w.size() > longest.size()) longest = w;
                else if(w.size() == longest.size() && w < longest)
                    longest = w;
            }
        }
        return longest;
    }
};
