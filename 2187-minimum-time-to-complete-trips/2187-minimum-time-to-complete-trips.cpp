class Solution {
public:
    bool valid(vector<int>& time, long long mid,int total){
        long long ans=0;
        for(auto &i:time){
            ans+=mid/i;
            if(ans>=total) return 1;
        }
        return 0;
    }
    
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,r=100000000000000;
        while(r-l>1){
            long long mid=l+(r-l)/2;
            if(valid(time,mid,totalTrips)) r=mid;
            else l=mid;
        }
        return r;
    }
};