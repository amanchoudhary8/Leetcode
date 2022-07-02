class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n,vector<int>{});
        vector<int> in(n,0);
        for(auto &pr:pre){
            in[pr[0]]++;
            graph[pr[1]].push_back(pr[0]);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++)
            if(!in[i]) q.push(i);
        
        
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &c:graph[node]){
                in[c]--;
                if(!in[c]) q.push(c);
            }
        }
        if(ans.size()<n) return {};
        return ans;
        
    }
};