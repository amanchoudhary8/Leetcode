class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long  ans=n,cur=0;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                cur++;
                ans+=cur;
            }
            else cur=0;
        }
        return ans;
    }
};