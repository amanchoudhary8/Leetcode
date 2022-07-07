class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> u;
        for(char &c:s){
            u[c]++;
        }
        sort(s.begin(),s.end(),[&](char c,char d){
            if(u[c]==u[d]) return c>d;
            return u[c]>u[d];
        });
        return s;
    }
};