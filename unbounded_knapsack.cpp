#include<bits/stdc++.h>
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0);
       // vector<int> cur(w+1,0);

    for(int wt=0;wt<=w;wt++){
        prev[wt]= ((int)(wt/weight[0])) * profit[0];
    }
    for(int ind=1;ind<n;ind++){
            for(int wt=0;wt<=w;wt++){
            int nottake=0+prev[wt];
            int take=0;
            if(weight[ind]<=wt) { 
                take=profit[ind]+prev[wt-weight[ind]];
            }
            prev[wt]=max(take,nottake);
        }
    }
    return prev[w];
}
