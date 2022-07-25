//INFOSYS QUES3 longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;

int sub(int a[],int i,int n,int prev){
    int x=0;
if(i==n) return 0;

 x=sub(a,i+1,n,prev);
int b=0;
if(a[i]>prev){
    b=1+sub(a,i+1,n,a[i]);
}
return max(b,x);
}
int main()
{
    int n;
    int res;
    cout<<"Enter size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter values of array\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    res=sub(a,0,n,0);

    return res;
}
