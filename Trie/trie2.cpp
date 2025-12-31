class Trie {
	public:
		TrieNode* children[26];
    	int wordCnt, prefixCnt;
	    TrieNode() {
	        for(int i=0;i<26;i++){
            	children[i]=nullptr;
        	}
        	wordCnt = 0;
			prefixCnt = 0;
	    }

	    void insert(string word) {
	        TrieNode* node=this;
			for(char ch:word){
				int index=ch-'a';
				if(node->children[index]==nullptr){
					node->children[index]=new TrieNode();
				}
				node=node->children[index];
				node->prefixCnt++;
			}
			node->wordCnt++;
    	}

	    int countWordsEqualTo(string word) {
	        TrieNode* node=this;
			for(char ch:word){
				int index=ch-'a';
				if(node->children[index]==nullptr){
					return 0;
				}
				node=node->children[index];
			}
			return node->wordCnt;
    	}

	    int countWordsStartingWith(string word) {
	        TrieNode* node=this;
			for(char ch:word){
				int index=ch-'a';
				if(node->children[index]==nullptr){
					return 0;
				}
				node=node->children[index];
			}
			return node->prefixCnt;
    	}

	    void erase(string word) {
	        TrieNode* node = this;
			for(char ch: word){
				int index = ch - 'a';
				TrieNode* next = node->children[index];
				next->prefixCnt--;
				node = next;
			}
			node->wordCnt--;
	    }
};