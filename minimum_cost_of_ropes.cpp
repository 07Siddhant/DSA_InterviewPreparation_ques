class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        
            priority_queue<long long, vector<long long>, greater<long long>> pq;
            
            long long sum=0;
            long long join=0;
            
            for(int i=0;i<n;i++){
                pq.push(arr[i]);
            }
            while(pq.size()>1){
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            pq.pop();
            
            join=first+second;
            
            pq.push(join);
            sum+=join;
            }
            return sum;
            
    }
};
