// approach-1
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans=new ListNode(-1);
        ListNode* ansHead=ans;
        ListNode* curr=head;

        while(curr!=NULL) {
            if(curr->val < x) {
                ListNode* newNode=new ListNode(curr->val);
                ans->next=newNode;
                ans=newNode;
            }
            curr=curr->next;
        }

        curr=head;
        while(curr!=NULL) {
            if(curr-> val >=x) {
                ListNode* newNode=new ListNode(curr->val);
                ans->next=newNode;
                ans=newNode;
            }
            curr=curr->next;
        }

        return ansHead->next;
    }
};