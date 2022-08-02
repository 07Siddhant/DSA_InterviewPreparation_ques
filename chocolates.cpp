#include<bits/stdc++.h>
int f(int i,int j1,int j2,vector<vector<int>> &grid,int rows,int cols,vector<vector<vector<int>>>&dp){
    if(j1<0 || j1>=cols || j2<0 || j2>=cols) return -1e9;
    
    if(i==rows-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    //explore all possible paths
    int maxi=-1e9;
    for(int dj1=-1;dj1<=+1;dj1++){
        for(int dj2=-1;dj2<=+1;dj2++){
            int value=0;
            if(j1==j2) value=grid[i][j1];
            else value=grid[i][j1]+grid[i][j2];
            value+=f(i+1,j1+dj1,j2+dj2,grid,rows,cols,dp);
            maxi=max(maxi,value);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,grid,r,c,dp);
}
