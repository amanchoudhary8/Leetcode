class Solution {
public:
    bool f(int i,int j,string &p,string &s,vector<vector<int>> &dp){
      
        if(i==0 && j==0) return 1;
        if(i==0) return 0;
        if(j==0){
            for(int k=0;k<i;k++){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        
         if(dp[i][j]!=-1) return dp[i][j];
        
        if((p[i-1]==s[j-1]) || (p[i-1]=='?')) return dp[i][j]=f(i-1,j-1,p,s,dp);
        if(p[i-1]=='*') return dp[i][j]=(f(i-1,j,p,s,dp)|| f(i,j-1,p,s,dp));
        return dp[i][j]=0;
        
    }
    
    bool isMatch(string s, string p) {
        int m=p.length(),n=s.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,p,s,dp);
    }
};