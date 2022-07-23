int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;
    int ss=INT_MAX;
    
    for(int i=1;i<n;i++){
        int fs=dp[i-1]+abs(heights[i-1]-heights[i]);
        if(i>1){
             ss=dp[i-2]+abs(heights[i-2]-heights[i]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1]; //since we taking 0 based indexing (n-1)
}
