/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node* head)
    {
        if(head == NULL || head->next == NULL) return head;
 
        Node* prev = NULL;
        
        while(head){
            Node* next = head->next;
            head->next = prev;
            head->prev = next;
            prev = head;
            head = next;
        }
        return prev;
    }
};
