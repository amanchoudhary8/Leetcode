class Solution {
public:
    int bs(vector<int>& v,int l,int r,int x){
        int n=r;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(v[m]<x)
                l=m;
            else r=m;
        }
        if(r<n && v[r]==x) return r;
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size(),r=n,l=-1;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(nums[m]>nums[n-1]){
                l=m;
            }
            else r=m;
        }
        //cout<<r;
        if(r==0) return bs(nums,-1,n,target);
        
        int x=bs(nums,-1,r,target);
        int y=bs(nums,r-1,n,target);
        if(x!=-1) return x;
        if(y!=-1) return y;
        return -1;
        
        
    }
};