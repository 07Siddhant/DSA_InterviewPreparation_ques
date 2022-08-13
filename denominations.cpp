#include<bits/stdc++.h>
int f(int ind,vector<int> &num, int tar, vector<vector<int>> &dp){
    if(ind==0){
        if(tar%num[0]==0) return tar/num[0];
        else return 1e9;
    }
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    int nottake=0+f(ind-1,num,tar,dp);
    int take=1e9;
    if(num[ind]<=tar) take=1+f(ind,num,tar-num[ind],dp);
    
    return dp[ind][tar]= min(nottake,take);
}
int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans=f(n-1,num,x,dp);
    if(ans>=1e9) return -1;
    return ans;
}
