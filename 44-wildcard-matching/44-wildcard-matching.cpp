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
        vector<int> prev(n+1,0),cur(n+1,0);
        prev[0]=1;
        for(int j=1;j<=n;j++) prev[j]=0;
        
        
        for(int i=1;i<=m;i++){
            cur[0]=prev[0] & (p[i-1]=='*');
            for(int j=1;j<=n;j++){
                if((p[i-1]==s[j-1]) || (p[i-1]=='?'))  cur[j]=prev[j-1];
                else if(p[i-1]=='*') cur[j]=(prev[j] || cur[j-1]);
                else cur[j]=0;
            }
            prev=cur;
        }        
        return prev[n];
    }
};