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
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m,n,word1,word2,dp);
        
    }
};