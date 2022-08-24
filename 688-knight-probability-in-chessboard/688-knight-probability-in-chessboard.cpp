class Solution {
public:
    typedef vector<double> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    double help(int i,int j,int n,int k, vvvi &dp){
        if(i<0 || j<0 || i>=n || j>=n){
           return 0;
        } 
        if(k==0) {
            return 1;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
            
        double res=0;
        res+=0.125 * help(i-2,j-1,n,k-1,dp);
        res+=0.125 * help(i-2,j+1,n,k-1,dp);
        res+=0.125 * help(i+2,j-1,n,k-1,dp);
        res+=0.125 * help(i+2,j+1,n,k-1,dp);
        res+=0.125 * help(i-1,j+2,n,k-1,dp);
        res+=0.125 * help(i+1,j+2,n,k-1,dp);
        res+=0.125 * help(i-1,j-2,n,k-1,dp);
        res+=0.125 * help(i+1,j-2,n,k-1,dp);
        
        return dp[i][j][k]=res;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vvvi dp(n,vvi(n,vi(k+1,-1)));
        return help(row,column,n,k,dp);
    }
};