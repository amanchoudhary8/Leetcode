class Solution {
public:
    bool valid(vector<int>& nums,int mid, int t){
        long long  ans=0;
        for(auto &i:nums){
            ans+=ceil(1.0*i/mid);
            if(ans>t) return 0;
        }
        return 1;
        
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=0,high=1000000;
        while(high-low>1){
            int mid=low+(high - low)/2;
            if(valid(nums,mid,threshold)) high=mid;
            else low=mid;
        }
        return high;
        
    }
};