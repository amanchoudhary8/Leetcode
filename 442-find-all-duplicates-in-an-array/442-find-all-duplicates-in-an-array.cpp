class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[nums[i]-1]!=nums[i]) swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) ans.push_back(nums[i]);
        }
        return ans;
    }
};


/*

//negation
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
*/