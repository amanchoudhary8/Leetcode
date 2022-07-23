class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size(),l=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(l<=i && sum-nums[l]>=target){
                sum-=nums[l];
                l++;
            }
            if(sum>=target)
                ans=min(ans,i-l+1);
            
        }
        if(ans==INT_MAX) ans=0;
        return ans;
    }
};