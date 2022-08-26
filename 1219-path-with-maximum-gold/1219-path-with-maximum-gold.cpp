class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    int dfs(int r,int c,int m,int n,vector<vector<bool>> &seen,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0 || seen[r][c])
            return 0;
        int ans=grid[r][c],maxi=0;
        seen[r][c]=1;
        
        for(int d=0;d<4;d++){
            maxi=max(maxi,dfs(r+dir[d],c+dir[d+1],m,n,seen,grid));
        }
        seen[r][c]=0;
        return ans+maxi;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> seen(m,vector<bool>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j,m,n,seen,grid));
            }
        }
        return ans;
    }
};