struct node{
    node* link[26];
    int cnt=0;
};


class WordDictionary {
    node *root;
public:
    WordDictionary() {
        root=new node();
    }
    
    void addWord(string word) {
        node* tmp=root;
        for(char &c:word){
            if(!tmp->link[c-'a']) {
                tmp->link[c-'a']=new node();
            }
            tmp=tmp->link[c-'a'];
        }
        tmp->cnt++;
    }
    
    bool search(string &word,int i,node * tmp) {
        int n=word.length();
        for(;i<n;i++){
            if(word[i]=='.'){
                bool flag=0;
                for(int x=0;x<26;x++){
                    if(tmp->link[x] && !flag){
                        flag|=search(word,i+1,tmp->link[x]);
                    }
                }
                return flag;
            }
            else {
                if(!tmp->link[word[i]-'a']) return 0;
                tmp=tmp->link[word[i]-'a'];
            }
        }
        if(word==".ad") cout<<tmp->cnt;
        return tmp->cnt;
    }

    
    
    bool search(string word) {
        return search(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */