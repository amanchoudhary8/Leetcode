class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp=matrix;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0) dp[i][j]+=min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==n-1) dp[i][j]+=min(dp[i-1][j],dp[i-1][j-1]);
                else dp[i][j]+=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[m-1][j]);
        }
        return ans;
    }
};