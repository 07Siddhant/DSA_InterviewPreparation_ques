bool canPartition(vector<int> &arr, int n)
{
	int totsum=0;
    for(int i=0;i<n;i++){
        totsum+=arr[i];
    }
    int target=totsum/2;
    vector<bool> prev(target+1,0);
     vector<bool> curr(target+1,0);
    if(totsum%2) return false;
    prev[0]=true,curr[0]=true;
    //for(int ind=0;ind<n;ind++) prev[0]=true;
    
  if(arr[0]<=target)  prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int k=1;k<=target;k++){
                 bool nottake=prev[k];
                  bool take=false;
             if(arr[ind]<=k) take=prev[k-arr[ind]];
           curr[k] = take | nottake;
        }
        prev=curr;
    }
    return prev[target];
}
