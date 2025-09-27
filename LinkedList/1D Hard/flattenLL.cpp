class Solution {
  public:
    
    Node* merge(Node* a, Node* b){
        Node dummy(-1);
        Node* tail = &dummy;
        
        while(a and b){
            if(a->data < b->data){
                tail->bottom = a;
                a = a->bottom;
            } else {
                tail->bottom = b;
                b = b->bottom;
            }
            tail = tail->bottom;
            tail->next = NULL;
        }
        tail->bottom = (a ? a: b);
        
        Node* p = tail->bottom;
        while(p){
            p->next = NULL;
            p = p->bottom;
        }
        return dummy.bottom;
        
    }
    
    Node *flatten(Node *root) {
        // code here
        if(!root or !root->next) return root;
        Node *h = flatten(root->next);
        root = merge(root, h);
        return root;
    }
};