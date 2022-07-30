class Solution {
public:
    
    vector<int> help(string str){
        int n=str.length();
        vector<int> pi(n);
        pi[0]=0;
        for(int i=1;i<n;i++){
            pi[i]=0;
            int j=pi[i-1];
            while(j && str[i]!=str[j]){
                j=pi[j-1];
            }
            if(str[j]==str[i]) pi[i]=j+1;
        }
        return pi;
        
    }
    
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int n=needle.size(),m=haystack.size();
        string s=needle+'$'+haystack;
        vector<int> pi=help(s);
        for(int i=n+1;i<n+m+1;i++) {if(pi[i]==n) return i-2*n;};
    
        return -1;
    }
};