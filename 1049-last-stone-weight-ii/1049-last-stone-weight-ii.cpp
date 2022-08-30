class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        
        int sum=0;
        sum=accumulate(stones.begin(),stones.end(),sum);
        bool dp[n+1][(sum/2)+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            dp[i][0] =1;
        }
        for(int i=1;i<=(sum/2);i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(sum/2);j++){
                if(stones[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-stones[i-1]] || dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];        
            }
            
        }
        
        for(int j=(sum/2);j>=0;j--){
            if(dp[n][j] ) return sum-2*j;
        }
        return sum;
    }
};