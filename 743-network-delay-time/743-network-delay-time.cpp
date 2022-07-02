class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());
        for(auto &node: times){
            graph[node[0]].push_back({node[1],node[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >p;
        vector<int> dis(n+1,INT_MAX);
        
        dis[k]=0;
        p.push({0,k});
        int ans=0;
        while(!p.empty()){
            auto pr=p.top();
            p.pop();
            int wt=pr.first;
            int node=pr.second;
         
            for(auto &it:graph[node]){
                int wt2=it.second;
                int ch=it.first;
                if(dis[ch]>wt+wt2) {
                    dis[ch]=wt+wt2;
                    p.push({wt+wt2,ch});
                }
            }            
        }
        
        for(int i=1;i<n+1;i++){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }    
            return ans;
            
            
    }
};