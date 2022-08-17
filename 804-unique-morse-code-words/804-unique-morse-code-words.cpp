class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> u;
    for(auto &w:words){
        string s="";
        for(auto &c:w){
            s+=arr[c-'a'];
        }
        u.insert(s);
    }
    return u.size();
    
    
    
    }
    
};