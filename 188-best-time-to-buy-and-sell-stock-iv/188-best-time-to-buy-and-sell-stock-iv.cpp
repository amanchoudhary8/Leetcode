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
        vector<int> dp(2*k+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int tr=2*k-1;tr>=0;tr--){
                int opt1=0+dp[tr];
                int opt2=0;
                if(!(tr&1)) opt2=-prices[i]+dp[tr+1];
                else opt2=prices[i]+dp[tr+1];

                dp[tr]=max(opt1,opt2);
            }
        }
        
        return dp[0];
    }
};