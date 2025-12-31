#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isEndOfWord=false;
    }


    void insert(string word){
        TrieNode* node=this;
        for(char ch:word){
            int index=ch-'a';
            if(node->children[index]==nullptr){
                node->children[index]=new TrieNode();
            }
            node=node->children[index];
        }
        node->isEndOfWord=true;
    }

    bool search(string word){
        TrieNode* node=this;
        for(char ch:word){
            int index=ch-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node=node->children[index];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix){
        TrieNode* node=this;
        for(char ch:prefix){
            int index=ch-'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node=node->children[index];
        }
        return true;
    }

    bool removeHelper(TrieNode* node, string word, int depth){
        if(node==nullptr){
            return false;
        }
        if(depth==word.size()){
            if(!node->isEndOfWord){
                return false;
            }
            node->isEndOfWord=false;
            for(int i=0;i<26;i++){
                if(node->children[i]!=nullptr){
                    return false;
                }
            }
            return true;
        }
        int index=word[depth]-'a';
        if(removeHelper(node->children[index], word, depth+1)){
            delete node->children[index];
            node->children[index]=nullptr;
            if(!node->isEndOfWord){
                for(int i=0;i<26;i++){
                    if(node->children[i]!=nullptr){
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
    
    void remove(string word){
        removeHelper(this, word, 0);
    }
};

int main(){
    TrieNode* root=new TrieNode();
    root->insert("hello");
    cout<<root->search("hello")<<endl; // Output: 1 (true
    cout<<root->search("hell")<<endl;  // Output: 0 (false)
    cout<<root->startsWith("hell")<<endl; // Output: 1 (true)
    cout<<root->startsWith("world")<<endl; // Output: 0 (false)
    root->insert("world");
    cout<<root->search("world")<<endl; // Output: 1 (true)
    root->remove("hello");
    cout<<root->search("hello")<<endl; // Output: 0 (false)
    return 0;
}