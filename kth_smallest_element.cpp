class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        for(l=0;l<k;l++)
        {
            pq.push(arr[l]);
        }
    
        for(int i=k;i<=r;i++)
        {
           // int tp=pq.top();
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            } 
            else continue;
        }
        int ans = pq.top();
        return ans;
    }
};
