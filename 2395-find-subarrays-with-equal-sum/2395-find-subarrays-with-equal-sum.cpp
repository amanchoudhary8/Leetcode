class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> u;
        int n=nums.size(),i=1;
        if(n==2) return 0;
        while(i<n){
            int sum=nums[i]+nums[i-1];
            u[sum]++;
            if(u[sum]>1) return 1;
            i++;
        }
        return 0;
    }
};