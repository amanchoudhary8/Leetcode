class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> v(10,0);
        for(char &c:num){
            v[c-'0']++;
        }
        string s="";
        char c=' ';
        for(int i=9;i>=0;i--){
            if(!v[i]) continue;
            if (v[i]==1  || (v[i] & 1)){
                if(c==' ')  c='0'+i;
                if(v[i]==1) continue;
            }
            
            if(!s.length() && !i) break;
            int k=v[i]/2;
            while(k--) s+='0'+i;
            
        }
        
        string s2=s;
        reverse(s2.begin(),s2.end());
        if(c!=' ') s+=c;
        if(!s.length()  && v[0]) return "0";
        return s+s2;
        
    }
};