//delete duplicates from sorted list 
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
	
void traverse(struct node* node) {
	while(node != NULL) {
		printf("->%d", node->data);
		node = node->next;
	}
	printf("\n");
}
	
void insertLast(struct node **head, int key) {
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = key;
	struct node *p = *head;
	new->next = NULL;
	
	if(*head == NULL) {
		*head = new;
		return;
	}
	while(p->next!=NULL) {
		p = p->next;
	}
	p->next = new;
}
	
void deleteDuplicates(struct node* head) {
	struct node *p, *q;
	p = head;
	q = head->next;
	while(q != NULL) {
		if(q->data == q->next->data) {
			p->next = q->next;
			p = p->next;
			q = q->next->next;
		} else {
			q = q->next;
			p = p->next;
		}
	}
	
}
	
int main() {
	struct node* head = NULL;
	insertLast(&head, 1);
	insertLast(&head, 2);
	insertLast(&head, 2);
	insertLast(&head, 5);
	insertLast(&head, 5);
	traverse(head);
	deleteDuplicates(head);
	traverse(head);
	return 0;
}