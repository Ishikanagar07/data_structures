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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL){
            return head;
        }
        
        //step 1
        Node* cur = head;
        Node* temp;
        
        while(cur != NULL) {
            temp = cur -> next;
            cur -> next = new Node(cur -> val);
            cur -> next -> next = temp;
            cur = temp;
        }
        
        
        //step 2
        cur = head;
        
        while(cur != NULL){
            if(cur -> random != NULL){
                cur -> next -> random = cur -> random -> next;
            }
            cur = cur -> next -> next;
        }
        
        
        //step 3
        Node* orig = head;
        Node* copy = head -> next;
        Node* cloneHead = copy;  //to store head of clone list
        
        while(orig != NULL && copy != NULL){
            orig -> next = orig -> next -> next;
            if(copy -> next != NULL) {
                copy -> next = copy -> next -> next;
            }
            orig = orig -> next;
            copy = copy -> next;
        }
        
        
        return(cloneHead);
    }
};
