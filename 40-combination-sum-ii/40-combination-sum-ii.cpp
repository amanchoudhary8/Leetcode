class Solution {
public:
    void help(int i,vector<int> &ds,vector<int>& can,vector<vector<int>> &ans, int target){
        if(target<0)
            return;      
        int n=can.size();
        if(i==n){
            if(target==0)
                ans.push_back(ds);
            
            return;
        }
            
        ds.push_back(can[i]);
        help(i+1,ds,can,ans,target-can[i]);
        ds.pop_back();
        
        if(ds.empty() || ds.back()!=can[i])
            help(i+1,ds,can,ans,target);
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<vector<int>> ans;
        vector<int> ds;
        help(0,ds,can,ans,target);
        return ans;
    }
};




//general backtrack
/*

class Solution {
public:
    
    void help(int i,vector<int> &ds,vector<int>& can,vector<vector<int>> &ans, int target){
        if(target<0)
            return;
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        int n=can.size();
        if(i==n)
            return;
        
        
        for(int j=i;j<n;j++){
            if(j!=i && can[j]==can[j-1]) continue;
            
            ds.push_back(can[j]);
            help(j+1,ds,can,ans,target-can[j]);
            ds.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<vector<int>> ans;
        vector<int> ds;
        help(0,ds,can,ans,target);
        return ans;
    }
};
*/