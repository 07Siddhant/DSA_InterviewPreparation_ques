int getMaxPathSum(vector<vector<int>> &matrix)
{ 
    int row=matrix.size();
   int cols=matrix[0].size();
    vector<int> prev(cols,0);
    vector<int> cur(cols,0);
    int r=0;
  //  int maxi=-1e9;
    if(r==0) 
        for(int j=0;j<cols;j++) prev[j]=matrix[0][j];
    
    for(int r=1;r<row;r++){
        
    for(int j=0;j<cols;j++){
      int up=matrix[r][j]+prev[j];
        
         int left=matrix[r][j];
        if(j-1>=0) left+=prev[j-1];
        else left+=-1e9;
        
        int right=matrix[r][j];
        if(j+1<cols) right+=prev[j+1];
            else right+=-1e9;
        
        cur[j]=max(up,max(left,right));
    }
        prev=cur;
    }
    int maxi=-1e9;
    for(int j=0;j<cols;j++){
        maxi=max(maxi,prev[j]);
    }
    return maxi;
}
