class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> v(26,0);
        int n=s.length();
        for(int i=0;i<n;i++)
            v[s[i]-'a']=i- v[s[i]-'a'];
        
        for(int i=0;i<26;i++)
            if(v[i] && v[i]-1!=distance[i]) return 0;
        
        return 1;
    }
};