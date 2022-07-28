class Solution{
    public:
    
    void heapify(vector<int> &temp,int n,int ind){
        int largest=ind;
        int left=2*ind+1;
        int right=2*ind+2;
        
        if(left < n && temp[largest]<temp[left]){
            largest=left;
        }
         if(right < n && temp[largest]<temp[right]){
             largest=right;
         }
         
         if(largest!=ind){
             swap(temp[largest],temp[ind]);
             heapify(temp,n,largest);
         }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> temp;
        
        for(auto it: a){
            temp.push_back(it);
        }
        for(auto it: b){
            temp.push_back(it);
        }
        int size=temp.size();
        for(int i=(size/2)-1;i>=0;i--){
            heapify(temp,size,i);
        }
        return temp;
    }
};
