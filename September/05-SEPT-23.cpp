class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        Node* cloneHead=new Node(-1);
        Node* clone=cloneHead;
        unordered_map<Node*,Node*> mp;

        while(curr!=NULL) {
            clone->next=new Node(curr->val);
            mp[curr]=clone->next;

            curr=curr->next;
            clone=clone->next;
        }

        clone=cloneHead->next;
        curr=head;

        while(clone!=NULL) {
          clone->random=mp[curr->random];
          clone=clone->next;
          curr=curr->next;
        }

        return cloneHead->next;
    }
};