class Solution {
public:
    string reverseWords(string s) {
        string ans="",cur="";
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(cur!=""){
                    reverse(cur.begin(),cur.end());
                    if(ans=="") ans+=cur;
                    else ans+=" "+cur;
                    
                    cur="";
                }
            }
            else{
                cur+=s[i];
            }
        }
        if(cur!=""){
            reverse(cur.begin(),cur.end());
            if(ans=="") ans+=cur;
            else ans+=" "+cur;
        }
        return ans;
    }
};