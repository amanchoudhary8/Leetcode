class Solution {
public:
    
    int help(int i,int tr,int n,int k,vector<int>& prices,vector<vector<int>> &dp){
        if((i==n) || (tr==k)) return 0;
        
        if(dp[i][tr]!=-1) return dp[i][tr];
        
        int opt1=0+help(i+1,tr,n,k,prices,dp);
        int opt2=0;
        if(!(tr&1)){
            opt2=-prices[i]+help(i+1,tr+1,n,k,prices,dp);
        }
        else{
            opt2=prices[i]+help(i+1,tr+1,n,k,prices,dp);
        }
        
        return dp[i][tr]=max(opt1,opt2);
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        return help(0,0,n,2*k,prices,dp);
    }
};