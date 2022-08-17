#include<bits/stdc++.h>
int f(int ind1,int ind2,string s,string t,vector<vector<int>> &dp){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    
if(s[ind1]==t[ind2]){
    return 1+f(ind1-1,ind2-1,s,t,dp);
}
return dp[ind1][ind2]=max(f(ind1-1,ind2,s,t,dp),f(ind1,ind2-1,s,t,dp));
}
int lcs(string s, string t)
{
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
}
