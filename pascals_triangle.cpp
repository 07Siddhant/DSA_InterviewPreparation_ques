#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> rows(n);
    for(int i=0;i<n;i++){
        rows[i].resize(i+1); //length of row increases by 1 at every step
        rows[i][0]=rows[i][i]=1;
    for(int j=1;j<i;j++){ //initially it will not work for top 2 rows
        rows[i][j]=rows[i-1][j-1]+rows[i-1][j];
    }
    }
    return rows;
}
