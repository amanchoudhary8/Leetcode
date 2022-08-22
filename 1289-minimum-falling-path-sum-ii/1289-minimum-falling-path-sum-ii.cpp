class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp=matrix;
        for(int i=1;i<m;i++){
            int min1=dp[i-1][0],j1=0,min2=dp[i-1][1],j2=1;
            if(min1>min2) {
                swap(min1,min2);
                swap(j1,j2);
            }
            for(int j=2;j<n;j++){
                if(dp[i-1][j]<min1){
                    
                    min2=min1;
                    j2=j1;
                    
                    min1=dp[i-1][j];
                    j1=j;
                } 
                else if(dp[i-1][j]<min2){
                   min2=dp[i-1][j];
                    j2=j;
                } 
            }
            for(int j=0;j<n;j++){
                dp[i][j]+=((j==j1) ? min2  : min1);
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[m-1][j]);
        }
        return ans;
    }
};