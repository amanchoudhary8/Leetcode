class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0,dif=nums[1]-nums[0],cur=0;
        for(int i=2;i<n;i++){
            if(dif==nums[i]-nums[i-1]){
                cur++;
                ans+=cur;
            }
            else{
                cur=0;
                dif=nums[i]-nums[i-1];
            }
        }
        return ans;
    }
};