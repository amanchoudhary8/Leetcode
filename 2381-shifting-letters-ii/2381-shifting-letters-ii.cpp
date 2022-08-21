class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> v(n+1,0);
        for(auto &x:shifts){
            v[x[0]]+=x[2]?1:-1;
            v[x[1]+1]+=x[2]?-1:1;
        }
        for(int i=0,sum=0;i<n;i++){
            sum=(sum+v[i])%26;
            s[i]='a'+ (26 + s[i]-'a'+sum)%26;
        }
        return s;
    }
};