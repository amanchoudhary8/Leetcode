class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1,maxi=1,n=s.length();
        int i=0;
        while(i<n-1){
            if(s[i+1]==s[i]+1) ans++;
            else maxi=max(maxi,ans),ans=1;
            
            i++;
        }
        maxi=max(maxi,ans);
        return maxi;
    }
};