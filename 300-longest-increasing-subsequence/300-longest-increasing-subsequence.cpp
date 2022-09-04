// class Solution {
// public:
//     int lis(int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
//         if(ind==nums.size()) return 0;
        
//         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
//         int nott=0+lis(ind+1,prev,nums,dp);
//         int tk=0;
//         if(prev==-1 || nums[prev]<nums[ind]) tk=1+lis(ind+1,ind,nums,dp);
//         return dp[ind][prev+1]=max(nott,tk);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> next(n+1,0),cur(n+1,0);
        
//         for(int ind=n-1;ind>=0;ind--){
//             for(int prev=-1;prev<ind;prev++){
//                 int nott=0+next[prev+1];
//                 int tk=0;
//                 if(prev==-1 || nums[prev]<nums[ind]) tk=1+next[ind+1];
//                 cur[prev+1]=max(nott,tk);
//             }
//             next=cur;
//         }
        
//         return next[-1 + 1];
//     }
// };



// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> v(n,1);
//         for(int i=1;i<n;i++)
//             for(int j=0;j<i;j++)
//                 if(nums[j]<nums[i]) v[i]=max(v[i],v[j]+1);
            
        
//         int ans=1;
//         for(auto &x:v) ans=max(ans,x);
//         return ans;
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        int ans=0;
        v.push_back(nums[0]);ans++;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>v.back()){
                 v.push_back(nums[i]); 
                 ans++;
            }
            
            else{
                int ind=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[ind]=nums[i];
            }
        }
        return ans;
    }
};
























