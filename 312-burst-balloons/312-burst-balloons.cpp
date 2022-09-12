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
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return help(1,n,nums,dp);
    }
};