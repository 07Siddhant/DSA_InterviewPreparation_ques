#include<bits/stdc++.h>
int point(int days,int last,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    if(days==0) {
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }  }
        return maxi;
    }
    if(dp[days][last]!=-1) return dp[days][last];
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int pointts=points[days][task]+point(days-1,task,points,dp);
            maxi=max(maxi,pointts); } }
    return dp[days][last]=maxi;}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return point(n-1,3,points,dp);
}
