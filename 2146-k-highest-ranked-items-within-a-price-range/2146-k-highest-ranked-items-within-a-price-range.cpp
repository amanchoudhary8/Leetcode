class Solution {
public:
    typedef vector<int> vi;
    typedef pair<int,int> ii;
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m=grid.size(),n=grid[0].size();
        priority_queue<vi,vector<vi>,greater<vi>> pq;
        int low=pricing[0],high=pricing[1];
        vector<vector<int>> ans;
        int x=start[0],y=start[1];
        queue<ii> q;
        q.push({x,y});
        if(grid[x][y]==0) return ans;
        if(grid[x][y]>=low && grid[x][y]<=high){
            vi tmp={0,grid[x][y],x,y};
            pq.push(tmp);
        } 
        grid[x][y]=-1;
        int dir[]={0,1,0,-1,0};
        int level=0;
        while(!q.empty() && pq.size()<k){
            level++;
            int z=q.size();
            while(z--){
                auto [a,b]=q.front();q.pop();
                for(int d=0;d<4;d++){
                    x=a+dir[d];
                    y=b+dir[d+1];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]>0){
                       q.push({x,y});
                       if(grid[x][y]>=low && grid[x][y]<=high)
                           pq.push({level,grid[x][y],x,y});
                       
                       grid[x][y]=-1;
                    }
                }
            }
        }
        while(!pq.empty() && ans.size()<k) {
            ans.push_back({pq.top()[2],pq.top()[3]});
            pq.pop();
        }
        return ans;
    }
};