class Solution {
public:
    int f(int i,int j,const string &word1,const string &word2,vector<vector<int>> &dp){
        if(i==0) return j;
        if(j==0) return i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1]) return dp[i][j]=f(i-1,j-1,word1,word2,dp);
        
        int opt1=f(i-1,j,word1,word2,dp);
        int opt2=f(i-1,j-1,word1,word2,dp);
        int opt3=f(i,j-1,word1,word2,dp);
        
        return dp[i][j]=1+min(opt1,min(opt2,opt3));
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>> dp(2,vector<int>(n+1,0));//2 rows only
        
        for(int j=0;j<=n;j++) dp[0][j]=j;
        
        for(int i=1;i<=m;i++){
            dp[i&1][0]=i;
            for(int j=1;j<=n;j++){
                 if(word1[i-1]==word2[j-1]) dp[i&1][j]=dp[(i-1)&1][j-1];
                 else{
                    int opt1=dp[(i-1)&1][j];
                    int opt2=dp[(i-1)&1][j-1];
                    int opt3=dp[i&1][j-1];
                     
                     dp[i&1][j]=1+min(opt1,min(opt2,opt3));
                 }
            }
        }
        
        return dp[m&1][n];
        
    }
};