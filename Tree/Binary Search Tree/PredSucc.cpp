class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* succ = NULL;
        Node* pred = NULL;
        Node* r = root;
        
        while(r){
            if(key <= r->data){
                r = r->left;
            }
            else{
                pred = r;
                r = r->right;
            }
        }
        
        r = root;
        
        while(r){
            if(key >= r->data){
                r = r->right;
            }
            else{
                succ = r;
                r = r->left;
            }
        }
        
        return {pred, succ};
        
    }
};