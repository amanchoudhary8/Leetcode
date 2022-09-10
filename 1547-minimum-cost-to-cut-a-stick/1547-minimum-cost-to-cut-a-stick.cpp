class Solution {
public:
    
    int mcm(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int cost=mcm(i,k-1,cuts,dp)+mcm(k+1,j,cuts,dp)+(cuts[j+1]-cuts[i-1]);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        return mcm(1,c,cuts,dp);
    }
};