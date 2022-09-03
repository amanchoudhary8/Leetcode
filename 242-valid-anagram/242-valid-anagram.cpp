class Solution {
public:
    bool isAnagram(string &s, string &t) {
        vector<int> v(26,0);
        for(auto &x:s) v[x-97]++;
        for(auto &x:t) v[x-97]--;
        
        for(auto &x:v) if(x) return 0;
        return 1;
    }
};