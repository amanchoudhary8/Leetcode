class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),maxi=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++) 
            if(matrix[0][i]=='1'){
                dp[0][i]=1;
                maxi=1;
            }
        
        for(int i=0;i<m;i++)
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                maxi=1;
            } 
        
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    maxi=max(maxi,dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};