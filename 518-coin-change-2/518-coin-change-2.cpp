class Solution {
public:
//     int help(int n,int amount, vector<int>& coins,vector<vector<int>> &dp){
//         if(amount==0) return 1;
//         if(n==0) return 0;
//         if(dp[n][amount]!=-1) return dp[n][amount];
        
//         int nott=help(n-1,amount,coins,dp);
//         int take=0;
//         if(amount>=coins[n-1]) take=help(n,amount-coins[n-1],coins,dp);
        
//         return dp[n][amount]=take+nott;
        
//     }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int nott=dp[j];
                int take=0;
                if(j>=coins[i-1]) take=dp[j-coins[i-1]];

                dp[j]=take+nott;
            }
        }
        return dp[amount];
    }
};