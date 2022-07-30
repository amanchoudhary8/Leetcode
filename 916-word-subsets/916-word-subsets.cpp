class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26);
        for(auto &word:words2){
            vector<int> tmp(26);
            for(auto &c:word){
                tmp[c-97]++;
            }
            for(int i=0;i<26;i++) v[i]=max(v[i],tmp[i]);
        }
        vector<string> ans;
        for(auto &word:words1){
            vector<int> tmp(26);
            for(auto &c:word){
                tmp[c-97]++;
            }
            int i;
            for(i=0;i<26;i++){
                if(tmp[i]<v[i]) break;
            } 
            if(i==26) ans.push_back(word);
        }
        return ans;
    }
};