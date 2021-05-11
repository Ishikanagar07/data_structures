class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        //to find mid
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        //to reverse in place
        ListNode* prev = NULL;
        ListNode* cur = slow;
        ListNode* nex;
        
        while(cur != NULL){
            nex = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nex;
        }
        //by the end of this loop prev will be pointing to the head of reversed linked list
        
        
        //to compare 
        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
};

//try on leetcode for practice
