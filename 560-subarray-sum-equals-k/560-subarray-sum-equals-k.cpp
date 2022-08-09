class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,sum=0;
        unordered_map<int,int> u;
        u[sum]=1;
        for(auto &i:nums){
            sum+=i;
            if(u.find(sum-k)!=u.end())
                ans+=u[sum-k];
            u[sum]++;
        }
        return ans;
    }
};