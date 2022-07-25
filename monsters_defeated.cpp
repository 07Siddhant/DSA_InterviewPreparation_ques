#include<bits/stdc++.h>
using namespace std;
int main(){
int num_monsters;
int exp;
cout<<"Enter the value of number of monsters\n";
cin>>num_monsters;
cout<<endl<<"Enter initial experience"<<endl;
cin>>exp;
int arr[num_monsters];
int monster_bonus;
map<int,int> monsters;
for(int i=0;i<num_monsters;i++){
        cout<<"Enter power of "<<i<<" monster   ";
          cin>>arr[i];
}
for(int i=0;i<num_monsters;i++){
        cout<<"Enter bonus of "<<i<<" monster   ";
        cin>>monster_bonus;
    monsters[arr[i]]=monster_bonus;
}
map<int,int>::iterator it;
int value,valBon,cnt=0;
for(it=monsters.begin();it!=monsters.end();it++){
    value=(*it).first;
    valBon=(*it).second;
    if(exp>=value){
        exp+=valBon;
        cnt++;
    }
    else{
        break;
    }
}
cout<<"Total Monsters defeated\n"<<cnt;
return 0;
}
