class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long> v1(n),v2(n);
        vector<int > ans(n);
        v1[0]=nums[0];v2[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            v1[i]=v1[i-1]*nums[i];
        }
        
        for(int i=n-2;i>=0;i--){
            v2[i]=v2[i+1]*nums[i];
        }
        ans[0]=v2[1];
        ans[n-1]=v1[n-2];
        for(int i=1;i<n-1;i++){
            ans[i]=v1[i-1]*v2[i+1];
        }
        return ans;
    }
};