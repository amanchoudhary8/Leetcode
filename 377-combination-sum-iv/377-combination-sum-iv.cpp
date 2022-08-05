class Solution {
public:
    
    int bt(vector<int>& nums,vector<int> &dp,int rem){
        if(rem<=0){
            if(rem==0) return 1;
            return 0;
        }
        if(dp[rem]!=-1) return dp[rem];
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=bt(nums,dp,rem-nums[i]);
        }
        dp[rem]=ans;
        return ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return bt(nums,dp,target);
    }
};