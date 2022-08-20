class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n,vector<int>(n,1e6));
        for(int i=0;i<n;i++) v[i][i]=0;
        for(auto &e:edges){
            v[e[0]][e[1]]=v[e[1]][e[0]]=e[2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    v[j][k]=min(v[j][k],v[j][i]+v[i][k]);
                }
            }
        }
        int ans=0,cnt=INT_MAX;
        for(int i=0;i<n;i++){
            int tmp=0;
            for(int j=0;j<n;j++){
                if(v[i][j]<=distanceThreshold) tmp++;
                
            }
            if(tmp<=cnt){
                cnt=min(cnt,tmp);
                ans=i;
            }
            
            
        }
        return ans;
    }
};