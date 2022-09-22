class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        string ans="",tmp="";
        for(auto &c:s){
            if(c==' '){
                reverse(tmp.begin(),tmp.end());
                if(ans=="") ans+=tmp;
                else ans+=" "+tmp;
                tmp="";
            }
            else tmp+=c;
        }
        
        return ans;
    }
};