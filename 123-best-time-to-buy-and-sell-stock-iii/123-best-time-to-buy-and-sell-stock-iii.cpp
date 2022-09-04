class Solution {
public:
    typedef vector<int> vi;//1D
    typedef vector<vi> vvi;//2d
    typedef vector<vvi> vvvi;//3d
    
    int f(int i,int buy,int cap,vector<int>& prices,vvvi &dp){
        if(i==prices.size()  || cap==0) return 0;
        
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            int opt1=-prices[i]+f(i+1,0,cap,prices,dp);
            int opt2= 0+ f(i+1,1,cap,prices,dp);
            return dp[i][buy][cap]=max(opt1,opt2);
        }
        else{
            int opt1=prices[i]+f(i+1,1,cap-1,prices,dp);
            int opt2= 0+ f(i+1,0,cap,prices,dp);
            return dp[i][buy][cap]=max(opt1,opt2);
        }
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vvvi dp(n,vvi(2,vi(3,-1)));
        return f(0,1,2,prices,dp);
    }
};