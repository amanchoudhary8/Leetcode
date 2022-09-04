class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> v(n,1),hash(n,0);
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && v[i]<v[j]+1){
                    v[i]=v[j]+1;
                    hash[i]=j;
                }
            }
        }
        
        int ind=max_element(v.begin(),v.end())-v.begin();
        vector<int> ans;
        ans.push_back(nums[ind]);
        while(hash[ind]!=ind){
            ind=hash[ind];
            ans.push_back(nums[ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};