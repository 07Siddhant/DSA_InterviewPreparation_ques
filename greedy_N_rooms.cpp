class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++){
            pair<int,int> temp=make_pair(start[i],end[i]);
            p.push_back(temp);
        }
        sort(p.begin(),p.end(),cmp);
        
        int count=1;
        int endtime=p[0].second;
        
        for(int i=1;i<n;i++){
            if(endtime < p[i].first){
                count++;
                endtime= p[i].second;
            }
            else continue;
        }
        return count;
    }
};
