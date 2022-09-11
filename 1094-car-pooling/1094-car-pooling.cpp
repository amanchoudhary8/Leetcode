class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dis(1001,0);
        for(auto &trip:trips){
            dis[trip[1]]+=trip[0];
            dis[trip[2]]-=trip[0];
        }
        if(dis[0]>capacity) return 0;
        int ans=INT_MIN;
        for(int i=1;i<1001;i++){
            dis[i]+=dis[i-1];
            ans=max(ans,dis[i]);
            if(ans>capacity) return 0;
        }
        return 1;
    }
};