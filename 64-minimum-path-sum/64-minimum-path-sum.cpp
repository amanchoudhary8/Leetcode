class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,grid[0][0]);
        for(int j=1;j<n;j++) dp[j]=grid[0][j]+dp[j-1];
        
        for(int i=1;i<m;i++){
            dp[0]+=grid[i][0];
            for(int j=1;j<n;j++){
                dp[j]=min(dp[j-1],dp[j])+grid[i][j];
            }
            
        }
        return dp[n-1];
    }
};