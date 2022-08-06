int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    for(int ind=0;ind<n;ind++) dp[ind][0]=1;
    
    if(num[0]<=tar) dp[0][num[0]]=1;
    
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=tar;sum++){
            int nottake=dp[ind-1][sum];
                   int take=0;
               if(num[ind]<=sum) take=dp[ind-1][sum-num[ind]];
             dp[ind][sum]= nottake+take;

        }
    }
   return dp[n-1][tar];
}
