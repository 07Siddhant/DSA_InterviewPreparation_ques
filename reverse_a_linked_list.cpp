class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        struct Node *dummy=NULL;
        
        while(head!=NULL){
            struct Node *next=head->next;
            head->next=dummy;
            dummy=head;
            head=next;
        }
        return dummy;
    }
    
};
