/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node *mergelists(Node *a,Node *b){
        Node *dummy=new Node(0);
        Node *temp=dummy;
        
        while(a!=NULL && b!=NULL){
            if(a->data < b->data){
                dummy->bottom=a;
                dummy=dummy->bottom;
                a=a->bottom;
            }
            else{
                 dummy->bottom=b;
                dummy=dummy->bottom;
                b=b->bottom;

            }
        }
        if(a) dummy->bottom=a;
        else
        dummy->bottom=b;
        
        return temp->bottom;
    }
    
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)  return root;
   
   root->next=flatten(root->next);
   
   root=mergelists(root,root->next);
   
   return root;
}

