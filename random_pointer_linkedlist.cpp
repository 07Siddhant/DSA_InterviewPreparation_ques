/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter=head;
        Node *front=head;
        
        while(iter!=NULL){
            front=iter->next;
            Node *copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random=iter->random->next;
            }
                iter=iter->next->next;
        }
      iter = head;
        Node *psuedonode=new Node(0);
        Node  *copy1=psuedonode;
        while(iter!=NULL){
            front=iter->next->next;
            copy1->next=iter->next; //points to first deep node
            iter->next=front;        //breaking link with deep node and points to front pointer
            copy1=copy1->next;      //copy ab first deep node mai aa gya
            iter=iter->next;
        }
        return psuedonode->next;
    }
};
