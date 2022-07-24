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
class Solution {
public:
    ListNode* midf(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* ans=slow->next;
        slow->next=0;
        return ans;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode dummy,*tail=&dummy;
        while(head1 && head2){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
            }
            else{
                 tail->next=head2;
                 head2=head2->next;
            }
            tail=tail->next;
        }
        if(head1) tail->next=head1;
        if(head2) tail->next=head2;
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid=midf(head);
        head=sortList(head);
        mid=sortList(mid);
        head=merge(head,mid);
        return head;
    }
};