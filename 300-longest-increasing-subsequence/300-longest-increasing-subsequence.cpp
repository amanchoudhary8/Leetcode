class Solution {
public:
    int lis(int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nott=0+lis(ind+1,prev,nums,dp);
        int tk=0;
        if(prev==-1 || nums[prev]<nums[ind]) tk=1+lis(ind+1,ind,nums,dp);
        return dp[ind][prev+1]=max(nott,tk);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return lis(0,-1,nums,dp);
    }
};