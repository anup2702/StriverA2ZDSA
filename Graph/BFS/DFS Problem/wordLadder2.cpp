class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty()){
            vector<string> words = q.front();
            q.pop();
            // erase used previous level words
            if(words.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
            }

            string word = words.back();
            if(word == endWord){
                if(ans.size()==0){
                    ans.push_back(words);
                } else if(ans[0].size() == words.size()){
                    ans.push_back(words);
                }
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        words.push_back(word);
                        q.push(words);
                        usedOnLevel.push_back(word);
                        words.pop_back();
                    } 
                }
                word[i] = original;
            }
        }
        return ans;
    }
};