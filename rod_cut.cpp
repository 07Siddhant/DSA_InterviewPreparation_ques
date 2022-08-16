#include<bits/stdc++.h>
int f(int ind,int rodlen,vector<int> &price,vector<vector<int>> &dp){
    if(ind==0){
        return rodlen*price[0];
    }
    if(dp[ind][rodlen]!=-1) return dp[ind][rodlen];
    int nottake=f(ind-1,rodlen,price,dp);
    int take=INT_MIN;
    int rod=ind+1;
    if(rodlen>=rod) take=price[ind]+f(ind,rodlen-rod,price,dp);
    
    return dp[ind][rodlen]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}
