/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode* ln;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp=[](ln one,ln two){
            return one->val>two->val;
        };
        
        priority_queue<ln,vector<ln>,decltype(comp)> p(comp);
        int n=lists.size();
        
        for(auto &i:lists){
            if(i) p.push(i);
        }
        ListNode* head=new ListNode(0),*tail=head;
        while(!p.empty()){
            tail->next=p.top();
            tail=tail->next;
            p.pop();
            
            if(tail->next) p.push(tail->next);
                
        }
        return head->next;
    }
};