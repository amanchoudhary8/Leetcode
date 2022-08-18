class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> u;
        for(auto &a:arr){
            u[a]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &[x,y]:u){
            pq.push({y,x});
        }
        int ans=0,cnt=0,n=arr.size();
        while(cnt<n/2){
            cnt+=(pq.top().first);
            pq.pop();
            ans++;
        }
        return ans;
    }
};