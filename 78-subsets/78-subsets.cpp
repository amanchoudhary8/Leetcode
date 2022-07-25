class Solution {
public:
    
    void help(int ind,vector<int> & cur,vector<int> &nums,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.emplace_back(cur);
            return;
        }
        cur.push_back(nums[ind]);
        help(ind+1,cur,nums,ans);
        cur.pop_back();
        help(ind+1,cur,nums,ans);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> cur;
        vector<vector<int>> ans;
        help(0,cur,nums,ans);
        return ans;
        
        /*
        //functional
        if(nums.size()==0)
            return {{}};
        vector<vector<int>> v;
        
        int p=nums.back();
        nums.pop_back();
        v=subsets(nums);
        int n=v.size();
        for(int i=0;i<n;i++){
            vector<int> v1=v[i];
            v1.push_back(p);
            v.push_back(v1);
        }
        return v;
        
        */
        
        
        
        
        
        
        /*
        //bit manipulation
        
        vector<vector<int>> v;
         int n=nums.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> v1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    v1.push_back(nums[j]);
                }
            }
            v.push_back(v1);
        }
        return v;
        */
        
        
        
        
        
        
    }
};