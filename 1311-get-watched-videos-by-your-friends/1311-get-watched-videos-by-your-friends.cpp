class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=watchedVideos.size();
        vector<string> ans;
        unordered_map<string,int> u;
        queue<int> q;
        vector<bool> seen(n,0);
        
        q.push(id);seen[id]=1;
        while(level--){
            int qs=q.size();
            if(qs==0) return ans;
            while(qs--){
                auto x=q.front();q.pop();
                for(auto &i:friends[x]){
                    if(!seen[i]){
                        seen[i]=1;
                        q.push(i);
                    }
                }
            }
        }
        
        while(!q.empty()){
            int i=q.front();q.pop();
            for(auto &x:watchedVideos[i]){
                u[x]++;
            }
        }
        for(auto &[x,y] : u){
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end(),[&](auto &x,auto& y){
            if(u[x]==u[y]) return x<y;
            return u[x]<u[y];
        });
        return ans;
        
        
    }
};