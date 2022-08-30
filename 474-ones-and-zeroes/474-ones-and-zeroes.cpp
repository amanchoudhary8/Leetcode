class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
    int knap(vector<string>& strs,int m,int n,int s,vvvi &dp){
        if(s==0 || (m==0 && n==0)) return 0;
        if(dp[s][m][n]!=-1) return dp[s][m][n];
        
        int z=count(strs[s-1].begin(),strs[s-1].end(),'0');
        int o=count(strs[s-1].begin(),strs[s-1].end(),'1');
        if(z<=m && o<=n)
            return dp[s][m][n]=max(knap(strs,m,n,s-1,dp),1+knap(strs,m-z,n-o,s-1,dp));
        else return dp[s][m][n]=knap(strs,m,n,s-1,dp);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vvvi dp(strs.size()+1,vvi(m+1,vi(n+1,-1)));
        return knap(strs,m,n,strs.size(),dp);
    }
};