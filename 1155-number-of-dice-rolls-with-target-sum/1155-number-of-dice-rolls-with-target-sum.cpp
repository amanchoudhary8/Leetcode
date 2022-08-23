class Solution {
public:
    #define mod 1000000007
    int dfs(int n,int t,int k,vector<vector<int>> &dp){
        if(n==0  && t==0) return 1;
        if(n==0 || t==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        
        int tmp=0;
        for(int i=1;i<=k;i++){
            if(i>t) break;
            else tmp=(tmp+dfs(n-1,t-i,k,dp)%mod)%mod;
        }
        return dp[n][t]=tmp;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return dfs(n,target,k,dp);
    }
};