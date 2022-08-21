class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(2,vector<int>(n,grid[0][0]));
        for(int j=1;j<n;j++) dp[0][j]=grid[0][j]+dp[0][j-1];
        
        for(int i=1;i<m;i++){
            dp[i%2][0]=dp[(i-1)%2][0]+grid[i][0];
            for(int j=1;j<n;j++){
                dp[i%2][j]=min(dp[(i-1)%2][j],dp[i%2][j-1])+grid[i][j];
            }
            
        }
        return dp[(m-1)%2][n-1];
    }
};