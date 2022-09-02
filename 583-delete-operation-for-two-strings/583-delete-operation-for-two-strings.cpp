class Solution {
public:
    int lcs(const string &a,const string &b){
        int m=a.length(),n=b.length();
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) dp[i&1][j]=1+dp[(i-1)&1][j-1];
                else dp[i&1][j]=max(dp[(i-1)&1][j],dp[i&1][j-1]);
            }
        }
        return dp[m&1][n];
    }
    
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};