class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        int n=coins.size();
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){      
            int tmp=INT_MAX;
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    tmp=min(tmp,dp[i-coins[j]]);
                }
                else break;
            }
            if(tmp==INT_MAX) dp[i]=INT_MAX;
            else dp[i]=tmp+1;
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};