// Reverse a sublist in a singly linked list 

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void traverse(struct node *node) {
	while(node!=NULL) {
		printf("->%d", node->data);
		node=node->next;
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

void reverse(struct node *head, int f, int l) {
	
	if(head == NULL || f == l) {
		return;
	}
	struct node *p, *temp;
	p = head->next;
	
	while( f++ < l ) {
		temp = p-> next;
		p->next = temp->next;
		temp->next = head->next;
		head->next = temp;
	}
	
}

int main() {
	
	struct  node *head = NULL;
	insertLast(&head, 1);
	insertLast(&head, 2);
	insertLast(&head, 3);
	insertLast(&head, 4);
	insertLast(&head, 5);
	traverse(head);
	reverse(head, 2, 4);
	traverse(head);
	
	return 0;
	
}