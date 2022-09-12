class Solution {
public:
    int help(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MIN;
        for(int k=i;k<=j;k++)
            ans=max(ans,nums[i-1]*nums[j+1]*nums[k]+help(i,k-1,nums,dp)+help(k+1,j,nums,dp));
        
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int ans=INT_MIN;
                for(int k=i;k<=j;k++)
                    ans=max(ans,nums[i-1]*nums[j+1]*nums[k]+dp[i][k-1]+dp[k+1][j]);

                dp[i][j]=ans;
            }
        }        
        return dp[1][n];        
    }
};