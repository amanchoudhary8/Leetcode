class Solution {
public:
    int mod=1e6+1;
    int help(int a,int b,int n,int i,int m,vector<int>& nums, vector<int>& mul, vector<vector<int>> &dp){
        if(i==m) return 0;
        if(dp[a][abs(b-(n-1))]!=mod) return dp[a][abs(b-(n-1))];
        int p1=nums[a]*mul[i] + help(a+1,b,n,i+1,m,nums,mul,dp);
        int p2=nums[b]*mul[i] + help(a,b-1,n,i+1,m,nums,mul,dp);
        return dp[a][abs(b-(n-1))]=max(p1,p2);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m,mod));
        return help(0,n-1,n,0,m,nums,multipliers,dp);
    }
};