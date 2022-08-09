class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cur=1;
        vector<int> ans(n,1);
        for(int i=1;i<n;i++){
            cur*=nums[i-1];
            ans[i]*=cur;
        }
        cur=1;
        for(int i=n-2;i>=0;i--){
            cur*=nums[i+1];
            ans[i]*=cur;
        }
        return ans;
    }
};