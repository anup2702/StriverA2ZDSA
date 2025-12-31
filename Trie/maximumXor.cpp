struct Node {
    Node* links[2];

    Node() {
        links[0] = links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) // if not contains
                node->put(bit, new Node());

            node = node->get(bit); 
        }
    }

    int getMax(int num) {
        Node* node = root;
        int mxNum = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // Prefer opposite bit
            if (node->containsKey(1 - bit)) {
                mxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }

        return mxNum;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        sort(nums.begin(), nums.end());
        vector<array<int, 3>> q;
        for(int i=0; i<n; i++){
            q.push_back({queries[i][1], queries[i][0], i});
        }
        sort(q.begin(), q.end());
        Trie trie;
        vector<int> ans(n, -1);

        int idx = 0;

        for(auto &it: q){
            int x = it[1], m = it[0], i = it[2];
            int maxi = 0;

            while(idx < nums.size() and nums[idx] <= m){
                trie.insert(nums[idx]);
                idx++;
            }

            if(idx != 0) ans[i] = trie.getMax(x);
        }
        return ans;
    }
};


// 1️⃣ Sort nums
// 2️⃣ Sort queries by m
// 3️⃣ Insert into trie only numbers ≤ m
// 4️⃣ Answer query using the trie
// 5️⃣ Restore order