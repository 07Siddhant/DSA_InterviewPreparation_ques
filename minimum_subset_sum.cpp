int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totsum=0;
    for(int i=0;i<n;i++){
        totsum+=arr[i];
    }
    int target=totsum;
    vector<bool> prev(target+1,0);
     vector<bool> curr(target+1,0);
   
    prev[0]=true,curr[0]=true;
    
    
      prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int k=1;k<=target;k++){
                 bool nottake=prev[k];
                  bool take=false;
             if(arr[ind]<=k) take=prev[k-arr[ind]];
           curr[k] = take | nottake;
        }
        prev=curr;
    }
    int mini=1e9;
    for(int l=0;l<=totsum/2;l++){
        if(prev[l]==true){
            mini=min(mini,abs(totsum-l)-l);
        }
    }
    return mini;
}
