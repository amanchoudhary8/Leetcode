struct node{
    node* link[2];    
};

class trie{
private:
    node* root;

public:
    trie(){
        root=new node();
    }
    
    void insert(int num){
        node* tmp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!tmp->link[bit]) tmp->link[bit]=new node();
            tmp=tmp->link[bit];
        }
    }
    
    int maxor(int num){
        node *tmp=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(tmp->link[!bit]){
                maxi=maxi|(1<<i);
                tmp=tmp->link[!bit];
            }
            else
                tmp=tmp->link[bit];
        }
        return maxi;
    }
    
    
    
};

class Solution {
public:    
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        for(auto &i:nums) t.insert(i);
        
        int maxi=0;
        for(auto &i:nums) maxi=max(maxi,t.maxor(i));
        
        return maxi;
    }
};
