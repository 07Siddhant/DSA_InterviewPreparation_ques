// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
  int countNodes(struct Node* root){
    if(root==NULL) return 0;
    
    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
}

    bool isCBT(struct Node* root,int index,int total){
        if(root==NULL) return true;
        
        if(index>=total) return false;
        else
        {
            bool left=isCBT(root->left,2*index+1,total);
            bool right=isCBT(root->right,2*index+2,total);
            
            return(left && right);
        }
    }
    
    bool isMaxorder(struct Node* root){
        if(root->left==NULL && root->right==NULL) return true;
        
        if(root->right==NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left=isMaxorder(root->left);
            bool right=isMaxorder(root->right);
            
            return(left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int totalcount=countNodes(tree);
        if(isCBT(tree,index,totalcount) && isMaxorder(tree))
        return true;
        else 
        return false;
    }
};
