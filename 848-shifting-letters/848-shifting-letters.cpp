class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long n=s.length(),tmp=0;
        for(int i=n-1;i>=0;i--){
            tmp+=shifts[i];
            s[i]='a'+(s[i]-'a'+tmp)%26;
        }
        return s;
    }
};