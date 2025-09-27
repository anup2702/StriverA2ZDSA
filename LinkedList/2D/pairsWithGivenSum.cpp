class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>> ans;
        Node* left = head;
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        Node* right = temp;
        
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if(left->data + right->data > target){
                right = right->prev;
            } else{
                left = left->next;
            }
        }
        return ans;
    }
};