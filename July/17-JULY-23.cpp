class Solution {
    private:
    ListNode* rev(ListNode* node) {
        ListNode* curr=node;
        ListNode* forward=NULL;
        ListNode* prev=NULL;

        while(curr!=NULL) {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);
        int temp=l1->val + l2->val;
        ListNode* node=new ListNode(temp%10);
        l1=l1->next;
        l2=l2->next;
        int carry=temp/10;
        ListNode* ans=node;

        while(l1!=NULL && l2!=NULL) {
            int sum=l1->val +l2->val +carry;
            ListNode* new_node=new ListNode(sum%10);
            node->next=new_node;
            node=node->next;
            l1=l1->next;
            l2=l2->next;
            carry=sum/10;
        }

        while(l1!=NULL) {
            int sum=l1->val +carry;
            ListNode* new_node=new ListNode(sum%10);
            node->next=new_node;
            node=node->next;
            carry=sum/10;
            l1=l1->next;
        }
       
        while(l2!=NULL) {
            int sum=l2->val +carry;
            ListNode* new_node=new ListNode(sum%10);
            node->next=new_node;
            node=node->next;
            l2=l2->next;
            carry=sum/10;
        }
        
        if(carry) {
            ListNode* new_node=new ListNode(carry);
            node->next=new_node;
            node=node->next;
        }
        ans=rev(ans);
        return ans;
    }
};