Node* addTwoNumList(Node* l1, Node* l2) {
	stack<int> s1,s2;
	while(l1!=NULL){
		s1.push(l1->data);
		l1=l1->next;
	}
	while(l2!=NULL){
		s2.push(l2->data);
		l2=l2->next;
	}
	int carry=0;
	Node* dummy = new Node();
  	dummy-> data = -1;
  	Node* temp = dummy;
  
	while(s1.empty()==false || s2.empty()==false){
      	int total = 0;
		if(s1.empty()==false){
			total += s1.top();
          	s1.pop();
		}
		if(s2.empty()==false){
			total +=s2.top();
          	s2.pop();
		}
		total += carry;
      	carry = total/10;
		Node* ptr = new Node();
		ptr -> data = total%10;
          
		temp -> next = ptr;
		temp = temp -> next;
		
	}
	if(carry!=0){
		Node* ptr = new Node();
      	ptr -> data = carry;
		temp -> next = ptr;
		ptr = ptr -> next;
	}
	return dummy -> next;
}
