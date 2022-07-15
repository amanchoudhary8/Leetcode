class Solution {
public:
    
    void dfs(int i,int j,int &ans,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size()|| j<0 || j>=grid[0].size() || !grid[i][j])
            return;
        ans++;
        grid[i][j] =0;
        int dir[]={0,1,0,-1,0};
        for(int k=0;k<4;k++)
            dfs(i+dir[k],j+dir[k+1],ans,grid);
        
            
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int final=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int ans=0;
                    dfs(i,j,ans,grid);
                    final=max(ans,final);
                }
            }
        }
        return final;
    }
};