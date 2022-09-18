class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n),suf(n);
        
        pre[0]=height[0];
        for(int i=1;i<n;i++)
            pre[i]=max(pre[i-1],height[i]);
    
        
        int mr=0;
        for(int i=n-1;i>=0;i--){
            mr=max(mr,height[i]);
            suf[i]=mr;
        }
        
        int ans=0;
        for(int i=0;i<n;i++) ans+=(min(pre[i],suf[i])-height[i]);
        return ans;
    }
};