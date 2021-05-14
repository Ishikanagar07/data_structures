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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* ptr1 = dummy1;
        ListNode* ptr2 = dummy2;
        
        while(head != NULL){
            if(head->val < x){
                ptr1->next = head;
                ptr1 = head;
            }
            else{
                ptr2 -> next = head;
                ptr2 = head;
            }
            head = head -> next;
        }
        ptr2 -> next = NULL;
        ptr1 -> next = dummy2 -> next;
        return(dummy1 -> next);
    }
};




/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]


Example 2:
Input: head = [2,1], x = 2
Output: [1,2]
*/
