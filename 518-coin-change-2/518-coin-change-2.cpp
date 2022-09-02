class Solution {
public:
    int help(int n,int amount, vector<int>& coins,vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(n==0) return 0;
        if(dp[n][amount]!=-1) return dp[n][amount];
        
        int nott=help(n-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[n-1]) take=help(n,amount-coins[n-1],coins,dp);
        
        return dp[n][amount]=take+nott;
        
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return help(n,amount,coins,dp);
    }
};