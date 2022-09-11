class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        typedef pair<int,int> pi;
        vector<pi> v;
        for(int i=0;i<n;i++)
            v.push_back({efficiency[i],speed[i]});
        
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum+=v[i].second;
            pq.push(v[i].second);
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*v[i].first);
        }
        return ans % (int)(1e9 + 7);
    }
};