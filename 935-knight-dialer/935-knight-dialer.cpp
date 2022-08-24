class Solution {
public:
    #define mod 1000000007;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    int dx[8]={2,2,-2,-2,1,-1,1,-1};
    int dy[8]={-1,1,-1,1,2,2,-2,-2};
    
    int help(int i,int j,int n,vvvi &dp){
        if(i<0 || j<0 || i>=4 || j>=3 || (i==3 && j==0) || (i==3 && j==2)){
           return 0;
        } 
        if(n==0) {
            return 1;
        }
        if(dp[i][j][n]!=-1) return dp[i][j][n];
            
        
        int tmp=0;
        for(int d=0;d<8;d++){
            tmp=(tmp + help(i+dx[d],j+dy[d],n-1,dp))%mod;
        }
        
        return dp[i][j][n]=tmp;
    }
    
    int knightDialer(int n) {
        if(n==1) return 10;
        vvvi dp(4,vvi(3,vi(n,-1)));
        
        int ans=0;
        for(int i=1;i<=9;i++){
            ans=(ans+help((i-1)/3,(i-1)%3,n-1,dp))% mod;
        }
        ans=(ans+help(3,1,n-1,dp))% mod;
        return ans;
    }
};