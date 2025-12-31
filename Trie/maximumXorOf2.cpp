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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for (int x : nums)
            trie.insert(x);

        int maxi = 0;

        for (int x : nums)
            maxi = max(maxi, trie.getMax(x));

        return maxi;
    }
};
