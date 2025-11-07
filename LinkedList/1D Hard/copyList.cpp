class Solution {
public:
    Node* copyRandomList(Node* head) {
        // inserting copy node
        Node* temp = head;
        while(temp){
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
        // connecting random
        temp = head;
        while(temp){
            Node* copyNode = temp->next;
            if(temp->random) copyNode->random = temp->random->next;
            else copyNode->random = NULL;
            temp = temp->next->next;
        }
        // extracting nodes
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        temp = head;
        while(temp){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummyNode->next;


    }
};