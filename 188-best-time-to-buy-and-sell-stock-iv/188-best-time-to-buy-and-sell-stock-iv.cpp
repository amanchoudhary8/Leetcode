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
    
    int maxProfit2(vector<int>& ps) {
        int res=0;
        for (auto i = 1; i < ps.size(); ++i) 
            res += max(0, ps[i] - ps[i - 1]);
        return res;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if (k * 2 >= prices.size()) 
            return maxProfit2(prices);
        
        
        
        int n=prices.size();
        vvi ahead(2,vi(k+1,0)),cur(2,vi(k+1,0));
        
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy){
                        int opt1=-prices[i]+ahead[0][cap];
                        int opt2= 0+ ahead[1][cap];
                        cur[buy][cap]=max(opt1,opt2);
                    }
                    else{
                        int opt1=prices[i]+ahead[1][cap-1];
                        int opt2= 0+ ahead[0][cap];
                        cur[buy][cap]=max(opt1,opt2);
                    }
                }
            }
            ahead=cur;
        }
        return ahead[1][k];
    
    }
};
