class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0,dif=0,cur=1;
        for(int i=1;i<n;i++){
            if(dif==nums[i]-nums[i-1]){
                cur++;
                if(cur>=3) {
                    ans+=(cur-2);
                }
            }
            else{
                cur=2;
                dif=nums[i]-nums[i-1];
            }
        }
        return ans;
    }
};