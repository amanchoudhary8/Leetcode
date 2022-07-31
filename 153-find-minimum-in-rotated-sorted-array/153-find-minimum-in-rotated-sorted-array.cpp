class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=-1,n=nums.size(),r=n;
        while(r-l>1){
            int m=l+(r-l)/2;
            if(nums[m]<=nums[n-1]) r=m;
            else l=m;
        }
        return nums[r];
    }
};