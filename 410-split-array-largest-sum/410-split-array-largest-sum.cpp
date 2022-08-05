class Solution {
public:
    bool valid(vector<int>& nums, int mid,int m){
        int ans=0,i=0,n=nums.size();
        while(i<n){
            if(nums[i]>mid) return 0;
            int tmp=mid;
            while(i<n && nums[i]<=tmp){
                tmp-=nums[i];
                i++;
            }
            ans++;
            if(ans>m) return 0;
        }
        return 1;
    }
    
    
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        int l=0,r=sum;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(valid(nums,mid,m)) r=mid;
            else l=mid;
        }
        return r;
    }
};