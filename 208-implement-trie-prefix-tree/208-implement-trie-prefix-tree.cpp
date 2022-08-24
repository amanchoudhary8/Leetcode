struct node{
    node* link[26];
    int cnt=0;
};

class Trie {
    node *root;
public:
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* tmp=root;
        for(char &c:word){
            if(!tmp->link[c-'a']) {
                tmp->link[c-'a']=new node();
            }
            tmp=tmp->link[c-'a'];
        }
        tmp->cnt++;
    }
    
    bool search(string word) {
        node* tmp=root;
        for(char &c:word){
            if(!tmp->link[c-'a']) return false;
            tmp=tmp->link[c-'a'];
        }
        return tmp->cnt;
    }
    
    bool startsWith(string prefix) {
        node* tmp=root;
        for(char &c:prefix){
            if(!tmp->link[c-'a']) return false;
            tmp=tmp->link[c-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */