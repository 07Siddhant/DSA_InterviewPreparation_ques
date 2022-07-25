class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *cur=dummy,*nex=dummy,*pre=dummy;
        int cnt=0;
        while(cur->next!=NULL){  //calculating length of linked list
            cur=cur->next;
            cnt++;
        }
        while(cnt>=k){
            cur=pre->next; //means current is pointing to head
            nex=cur->next; //means pointing to current+1 element
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;  //cur k pichle wle element mai point krega
            cnt-=k;
        }
        return dummy->next;
    }
};
