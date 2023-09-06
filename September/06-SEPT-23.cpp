class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* curr=head;

        while(curr!=NULL) {
          size++;
          curr=curr->next;
        }

        int partSize=size/k;
        int extraPart=size%k;
        vector<ListNode*> ans(k);

        curr=head;
        int index=0;

        while(curr!=NULL) {
          int currSize=0;
          int extraNode=extraPart?1:0;
          extraPart=max(0,extraPart-1);
          ListNode* currHead=curr;

          while(curr!=NULL && currSize<(partSize+extraNode-1)) {
            currSize++;
            curr=curr->next;
          }
          ListNode* forward=curr->next;
          curr->next=NULL;
          ans[index++]=currHead;
          curr=forward;
        }

        return ans;
    }
};