class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(101,0);
        for(auto &i:logs){
            v[i[0]-1950]++;
            v[i[1]-1950]--;
        }
        
        int maxi=v[0],year=0; 
        for(int i=1;i<101;i++){
            v[i]+=v[i-1];
            if(v[i]>maxi){
                maxi=v[i];
                year=i;
            }
        }
        return year+1950;
    }
};