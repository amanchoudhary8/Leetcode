class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        queue<string> q;
        q.push(beginWord);st.erase(beginWord);
        int ladder=0;
        while(!q.empty()){
            int n=q.size(); ladder++;
            while(n--){
                string s=q.front(); q.pop();
                if(s==endWord) return ladder;
                int tl=s.length();
                for(int i=0;i<tl;i++){
                    char c=s[i];
                    for(int k=0;k<26;k++){
                        s[i]='a'+k;
                        if(st.find(s)==st.end()) continue;
                        q.push(s);
                        st.erase(s);
                    }
                    s[i]=c;
                }
            }
        }
        return 0;
    }
};