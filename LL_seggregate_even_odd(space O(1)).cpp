void seperate(node **head) {
	if (*head == NULL || (*head)->next == NULL) {
		return;
	}

	node* prev = NULL;
	node* curr = *head;
	node* end = *head;
	while (curr && !(curr->data%2 == 0)) {
		prev = curr;
		curr = curr->next;
		end = curr;
	}

	while (curr) {
		if (curr->data%2 == 0) {
			end = curr;
		} else {
			end->next = curr->next;

			if (prev) {
				curr->next = prev->next;
				prev->next = curr;
				
			} else {
				curr->next = *head;
				*head = curr;
			}

			prev = curr;
		}

		curr = curr->next;
	}
}
