class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>> dp(3,vector<int>(2,0));
        
        for(int i=n-1;i>=0;i--){
            dp[i%3][1]=max(-prices[i]+dp[(i+1)%3][0],dp[(i+1)%3][1]);
            dp[i%3][0]=max(prices[i]+dp[(i+2)%3][1],dp[(i+1)%3][0]);
        }
        return dp[0][1];
    }
};