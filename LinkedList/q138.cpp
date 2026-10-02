/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// check submissions, hashmap soln and O(1) soln
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node *tmp=head;
        while(tmp!=NULL) {
            Node *newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }
        tmp=head;
        while(tmp!=NULL) {
            if(tmp->random!=NULL) {
                tmp->next->random = tmp->random->next;
            }
            tmp = tmp->next->next;
        }
        
        tmp = head;
        Node *tmp2, *head2;
        tmp2 = head2 = head->next;
        while(tmp!=NULL) {
            tmp->next = tmp->next->next;
            tmp=tmp->next;
            if(tmp2->next!=NULL) {
                tmp2->next = tmp2->next->next;
                tmp2 = tmp2->next;
            }
        }
        return head2;
    }
};