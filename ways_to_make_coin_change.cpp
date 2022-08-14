#include<bits/stdc++.h>
long f(int ind,int *denominations,int tar,vector<vector<long>> &dp){
    if(ind==0){
        return (tar%denominations[0]==0) ;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    long nottake=f(ind-1,denominations,tar,dp);
    long take=0;
    if(denominations[ind]<=tar) 
        take=f(ind,denominations,tar-denominations[ind],dp);
    
    return dp[ind][tar]= take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
   return f(n-1,denominations,value,dp);
}
