class Solution {
    public:
    ListNode* reverseList(ListNode *mid){
        ListNode *pre=NULL;
        ListNode *dummy=NULL;S
        while(mid!=NULL){
            dummy=mid->next;
            mid->next=pre;
            pre=mid;
            mid=dummy;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val!=slow->val) return false;
            
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
