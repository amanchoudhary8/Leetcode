class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> us={'a','e','i','o','u'};
        int n=s.length();
        int i=0,j=0,tmp=0,maxi=0;
        while(j<n){
            if(us.find(s[j])!=us.end())  tmp++;
            if(j>=k){
                if(us.find(s[i])!=us.end()) tmp--;
                i++;
            }
            maxi=max(maxi,tmp);
            j++;
        }
        return maxi;
    }
};