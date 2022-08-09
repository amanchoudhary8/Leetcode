class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> u;
        int z=0,one=0;
        u[0]=-1;
        int n=nums.size(),ans=0;;
        for(int i=0;i<n;i++){
            if(nums[i]) one++;
            else z++;
            int d=one-z;
            //cout<<d<<" ";
            if(u.find(d)!=u.end())
                ans=max(ans,i-u[d]);
            else
                u[d]=i;
        }
        return ans;
        
    }
};