class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        stack<int> s;
        
        
        //to find mid
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != NULL){
            slow = slow->next;
        }
        
        
        //to compare
        while(slow != NULL){
            int x = s.top();
            s.pop();
            
            if(slow->val != x){
                return false;
            }
            slow = slow->next;
        }
        return true;
        
    }
};

//refer leetcode for practice
