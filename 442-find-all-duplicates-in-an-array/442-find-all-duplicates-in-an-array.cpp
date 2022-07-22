class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(auto &i:nums){
            int x=abs(i);
            if(nums[x-1]<0) ans.push_back(x);
            else nums[x-1]*=-1;
            
        }
        return ans;
    }
};