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
        vector<int> next(n+1,0),cur(n+1,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=-1;prev<ind;prev++){
                int nott=0+next[prev+1];
                int tk=0;
                if(prev==-1 || nums[prev]<nums[ind]) tk=1+next[ind+1];
                cur[prev+1]=max(nott,tk);
            }
            next=cur;
        }
        
        return next[-1 + 1];
    }
};