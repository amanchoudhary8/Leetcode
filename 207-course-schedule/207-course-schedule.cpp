class Solution {
public:
    
    bool dfs(int node,vector<int> &color,vector<vector<int>> &graph){
        color[node]=1;
        for(auto &ch:graph[node]){
            if(color[ch]==1) return 1;
            if(color[ch]==2) continue;
            if(dfs(ch,color,graph)) return 1;
        }
        color[node]=2;
        return 0;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n,vector<int>{});
        for(auto &pr:pre)
            graph[pr[1]].push_back(pr[0]);
        
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(!color[i] ){
                if(dfs(i,color,graph)) return false;
            }
        }
        return true;
    }
};