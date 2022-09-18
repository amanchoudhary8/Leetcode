class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vvi si;
        for(int i=0;i<n;i++)
            si.push_back({spells[i],i});
        sort(si.begin(),si.end());
        sort(potions.rbegin(),potions.rend());
        
        vector<int> ans(n);
        int i=0,j=0,m=potions.size();
        while(i<n){
            while(j<m && 1ll*potions[j]*si[i][0]>=success) j++;
            ans[si[i][1]]=j;
            
            i++;
        }
        return ans;
    }
};