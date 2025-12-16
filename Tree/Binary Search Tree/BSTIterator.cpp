class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* el = st.top();
        st.pop();
        pushAll(el->right);
        return el->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
private:
    void pushAll(TreeNode* node){
        for(; node != NULL; st.push(node), node = node->left);
    }
};


// space o(h), time o(1)