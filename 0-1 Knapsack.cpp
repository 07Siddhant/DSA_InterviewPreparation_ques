int knapsack(vector<int> w, vector<int> val, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int W=w[0];W<=maxWeight;W++) dp[0][W]=val[0];
    
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int nottake=0+dp[ind-1][W];
              int take=INT_MIN;
        if(w[ind]<=W)  take=val[ind]+dp[ind-1][W-w[ind]];
    
          dp[ind][W]= max(take,nottake);
        }
    }
	return dp[n-1][maxWeight];
}
