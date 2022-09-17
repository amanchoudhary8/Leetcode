typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vvi difpr;
        for(int i=0;i<n;i++)
            difpr.push_back({profit[i],difficulty[i]});
        
        sort(worker.rbegin(),worker.rend());
        sort(difpr.rbegin(),difpr.rend());
        
        int i=0,m=worker.size(),j=0;
        int ans=0;
        while(i<m && j<n){
            if(difpr[j][1]>worker[i]) j++;
            else{
                ans+=difpr[j][0];i++;
            }
        }
        return ans;
    }
};