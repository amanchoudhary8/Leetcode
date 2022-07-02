class Solution {
public:
    
    bool dfs(int node,vector<bool> &vis,vector<bool> &dfsvis,vector<bool> &ans,vector<vector<int>>& graph){
        vis[node]=1;
        if(graph[node].size()==0) {
            ans[node]=1;
            return true;
        }
        
        dfsvis[node]=1;
        bool cur=1;
        for(int &i:graph[node]){
            if((!vis[i]))
                cur=cur && dfs(i,vis,dfsvis,ans,graph);
            else if(dfsvis[i]) return false;
            else if(!ans[i])  cur=0;  
            
        }
        
          dfsvis[node]=0;
          if(cur) ans[node]=1;;
          return cur;
          
        }

    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,0),dfsvis(n,0),safe(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,vis,dfsvis,safe,graph);        
            
        }
        for(int i=0;i<n;i++)
            if(safe[i]) ans.push_back(i);
        
        return ans;
    }
};