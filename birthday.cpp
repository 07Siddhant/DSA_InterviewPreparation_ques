#include<bits/stdc++.h>
using namespace std;

int counter(int n,int k){
    int cnt=0;
if(k==1) return n;
else
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j%i==0) cnt++;
        }
    }
return cnt;
}



int count_Array(int n,int k){
if(k==1) return n;

if(k>=2) return counter(n,k);
}



int main()
{
   int n,k;
   cout<<"Enter value of n \n";
   cin>>n;
    cout<<"Enter value of k for length of each array\n";
    cin>>k;
     cout<< count_Array(n,k);
     return 0;
}
