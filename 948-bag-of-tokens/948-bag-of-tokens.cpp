class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int maxi=0;
        int i=0,j=tokens.size()-1,score=0;
        while(i<=j){
            if(tokens[i]<=power){
                score++;
                maxi=max(maxi,score);
                power-=tokens[i];
                i++;
            }
            else if(score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            else break;
        }
        return maxi;
    }
};