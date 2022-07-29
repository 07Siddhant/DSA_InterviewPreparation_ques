class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isAllocationPossible(int barrier,int books,int arr[],int k){
       int allstu=1,pages=0;
        for(int i=0;i<books;i++){
            if(arr[i]>barrier) return false;
            if(pages+arr[i] > barrier){
                allstu++;
                pages=arr[i];
                if(allstu>k) return false;
            }
            else
            pages+=arr[i];
        }
          
           return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(N<M) return -1;
        
        long long max=0;
        
        for(int i=0;i<N;i++){
            max+=A[i];
        }
        int low=0,high=max;
        int res=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(isAllocationPossible(mid,N,A,M)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};
