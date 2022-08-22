class Solution {
public:
    int h(vector<int>& coins, int target,vector<int> &dp){
        if(target==0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ans=INT_MAX;
        int n=coins.size();
        for(int i=0;i<n;i++){
            if(coins[i]<=target)
                ans=min(ans,h(coins,target-coins[i],dp));
        }
        if(ans==INT_MAX) return dp[target]=INT_MAX;
        return dp[target]=ans+1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans= h(coins,amount,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};