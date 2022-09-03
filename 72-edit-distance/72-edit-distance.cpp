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
        int m=word1.size(),n=word2.size();
        vector<int> dp(n+1,0);//1 rows only
        
        for(int j=0;j<=n;j++) dp[j]=j;
        int prev;
        for(int i=1;i<=m;i++){
            prev=dp[0];
            dp[0]=i;
            for(int j=1;j<=n;j++){
                int cur=dp[j];
                 if(word1[i-1]==word2[j-1]) dp[j]=prev;
                 else{
                    int opt1=dp[j];
                    int opt2=prev;
                    int opt3=dp[j-1];
                     
                    dp[j]=1+min({opt1,opt2,opt3});
                 }
                 prev=cur;
            }
        }
        
        return dp[n];
        
    }
};