class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        unordered_map<int,int> u;
        int start=0;
        for(int i=0;i<n;i++){
            int x=nums[i],j=0;
            while(x){
                if(x&1){
                    if(u.find(j)!=u.end())
                        start=max(start,u[j]+1);
                    u[j]=i;;
                }
                x=x>>1;
                j++;
            }
            ans=max(ans,i-start+1);
        }
        
        return ans;
    }
};