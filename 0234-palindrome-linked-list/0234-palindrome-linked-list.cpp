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
    ListNode* middle(ListNode* &head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
    }
    ListNode* reverse(ListNode* &head){
        ListNode* current=head;
        ListNode* prev=NULL;
       

        while(current!=NULL){
            ListNode* forward=current->next;
            current->next=prev;
            prev=current;
            current=forward;
        }
        return prev;
        
    }
    bool isPalindrome(ListNode* head) {

        ListNode* mid=middle(head);
        ListNode* midprev=reverse(mid);
        

        ListNode* Listone=head;
        
        while(midprev!=NULL){
            if(Listone->val!=midprev->val){
                return false;
            }
            Listone=Listone->next;
            midprev=midprev->next;
        }
        return true;

    }
};