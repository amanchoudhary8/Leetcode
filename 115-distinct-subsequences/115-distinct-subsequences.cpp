class Solution {
public:
    int f(int i,int j,const string &s,const string &t,vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int dont=f(i-1,j,s,t,dp);
        int tk=0;
        if(s[i-1]==t[j-1]) tk=f(i-1,j-1,s,t,dp);
        return dp[i][j]=dont+tk;
    }
    
    
    
    int numDistinct(string s, string t) {
        int m=s.length(),n=t.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,s,t,dp);
    }
};