class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        
        if(N<M) return -1;
        
        int days=0;
        int sundays=S/7;
        int totalfood=S*M;
        
        int buy=S-sundays;
        if(totalfood%N==0){
            days=totalfood/N;
        }
        else{
            days=totalfood/N+1;
        }
        if(days<=buy) return days;
        
        else return -1;
        
    }
};
