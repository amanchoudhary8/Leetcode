class Solution {
public:
    bool f(int i,int j,string &p,string &s,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i==0) return 0;
        if(j==0){
            for(int k=i-1;k>=0;k-=2){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[i-1]==s[j-1] || p[i-1]=='.') return dp[i][j]=f(i-1,j-1,p,s,dp);
        if(p[i-1]=='*'){
            bool opt1=f(i-2,j,p,s,dp);
            bool opt2=0;
            if(p[i-2]=='.') opt2=f(i,j-1,p,s,dp);
            else if(p[i-2]==s[j-1]) opt2=f(i,j-1,p,s,dp);
            return dp[i][j]=opt1 || opt2;
        }
        return dp[i][j]=0;
    }
    
    bool isMatch(string s, string p) {
        int m=p.length(),n=s.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,p,s,dp);
    }
};