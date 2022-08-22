class Solution {
public:
    int help(int i,vector<int>& days, vector<int>& costs,vector<int> &dp){
        int n=days.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        
        ans=min(costs[0]+help(i+1,days,costs,dp),ans);
        
        int j=i+1;
        while(j<n){
            if(days[j]< days[i]+7 ) j++;
            else break;
        }
         ans=min(costs[1]+help(j,days,costs,dp),ans);
        
        j=i+1;
        while(j<n){
            if(days[j]< days[i]+30 ) j++;
            else break;
        }
         ans=min(costs[2]+help(j,days,costs,dp),ans);
        
        return dp[i]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(),-1);
        return help(0,days,costs,dp);
            
    }
};