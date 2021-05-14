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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        
        ListNode* slow = head, *fast = head, *prev = NULL, *l1 = head;
        
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        prev -> next = NULL;
        
        ListNode* l2 = reverse(slow);
        
        merge(l1,l2);
    }
    
    
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *cur = head, *nex=NULL;
        while(cur != NULL){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
    
    
    void merge(ListNode* l1, ListNode* l2){
        ListNode* n1;
        ListNode* n2;
        while(l1 != NULL){
            n1 = l1->next;
            n2 = l2->next;
            l1->next = l2;
            
            if(n1 == NULL)
                break;
            
            l2->next = n1;
            l1 = n1;
            l2 = n2;
        }
    }
};


//refer leetcode and youtube 

/* 
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/
