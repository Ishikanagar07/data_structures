class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;

        Node* temp1 = head;
        Node* temp2; 
        
        while (temp1) {
            temp2 = new Node(temp1->val);
            m[temp1] = temp2;
            temp1 = temp1->next;
        }
        
        temp1 = head;
        
        while (temp1) {
            temp2 = m[temp1];
            temp2->next = m[temp1->next];
            temp2->random = m[temp1->random];
            temp1 = temp1->next;
        }
        return m[head];
    }
