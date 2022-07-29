/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<bits/stdc++.h>
class compare{
    public:
    bool operator() (Node<int>* a,Node<int>* b)
    {
        return a->data > b->data;
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minHeap;
    int k=listArray.size();
    if(k==0) return NULL;
    for(int i=0;i<k;i++){
        //means head of first linked list is not null
        if(listArray[i] !=NULL){
            minHeap.push(listArray[i]);
        } 
    }
    Node<int>* head=NULL;
    Node<int>* tail=NULL;
    while(minHeap.size()>0){
        Node<int>* top=minHeap.top();  //points to first smallest elements among first elements of k linkedlist.
        minHeap.pop();
        
        if(top->next!=NULL){ //means 1st element is inserted which is smallest
            minHeap.push(top->next);
        }
        
        if(head==NULL ){
            // answer linked list is empty
            head=top;
            tail=top;
        }
        else{
            // insert at linked list
            tail->next=top;
            tail=top;
        }
        
    }
    return head;
}
