class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n&1) return {};
        sort(changed.begin(),changed.end());
        unordered_map<int,int> u;
        vector<int> ans;
        
        int zero=0,i=0;
        while(i<n && changed[i]==0){
            zero++;
            i++;
        }
        if(zero & 1) return {};
        zero/=2;
        while(zero--) ans.push_back(0);
        
        for(;i<n;i++){
            int cur=changed[i];
            if(cur&1  || u.find(cur/2)==u.end() || u[cur/2]==0) u[cur]--;
            else{
                u[cur/2]++;
                ans.push_back(cur/2);
            } 
        }
        for(auto &[a,b]:u)
            if(b<0) return {};
        
        return ans;
    }
};