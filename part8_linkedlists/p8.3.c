//Check if there is a cycle in a singly linked list

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

int checkLoop(struct node *head) {
	
	struct node *p, *q;
	
	p = q = head;
	
	do {
		p = p->next;
		q = q->next;
		q = q!=NULL ? q->next : NULL;
	} while(q && p && p!=q);
	
	if(p == q ) {
		return 1;
	} else {
		 return 0;
	}
}

int main() {
	
	struct node *head1, *head2;
	head1 = head2 = NULL;
	
	insertLast(&head1, 10);
	insertLast(&head1, 20);
	insertLast(&head1, 30);
	traverse(head1);
	
	int t = checkLoop(head1);
	if(t){
		printf("Loop found!\n");
	} else {
		printf("No loop!\n");
	}
	
	insertLast(&head2, 10);
	insertLast(&head2, 30);
	insertLast(&head2, 40);
	
	traverse(head2);
	
	struct node *t1, *t2;
	
	t1 = head2->next;
	t2 = head2->next->next;
	t2->next = t1;
	
	t = checkLoop(head2);
	if(t) {
		printf("Loop found!\n");
	} else {
		printf("No loop!\n");
	}
	
	return 0;
}