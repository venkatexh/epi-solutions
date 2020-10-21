//Check if overlapping node is present in two cycle-free singly linked lists

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

int findLength(struct node *head) {
	struct node *p = head;
	int c = 0;
	while(p) {
		p = p->next;
		c++;
	}
	return c;
}

int checkOverlap(struct node *first, struct node *second) {
	
	int c1 = findLength(first);
	int c2 = findLength(second);
	
	int d = c1 > c2 ? c1-c2 : c2-c1;
	
	if(first == NULL || second == NULL){
		return 0;
	}
	struct node *p, *q;
	p = first;
	q = second;
	
	while(d--) {
		if(c1 > c2) {
			p = p->next;
		} else {
		q = q-> next;
		}
	}
	
	
	while(p != NULL && q != NULL) {
		if(p == q) {
			return 1;
		}
		p = p->next;
		q = q->next;
		
	}
	return 0;
}

void createLink(struct node **first, struct node **second) {
	
	(*first)->next->next = (*second)->next->next->next;
	
}

int main() {
	
	struct node *head1, *head2;
	head1 = NULL;
	head2 = NULL;
	
	insertLast(&head1, 2);
	insertLast(&head1, 4);
	insertLast(&head2, 5);
	insertLast(&head2, 6);
	insertLast(&head2, 8);
	insertLast(&head2, 9);
	
	traverse(head1);
	traverse(head2);
	
	createLink(&head1, &head2);
	
	int w = checkOverlap(head1, head2);
	if(w) {
		printf("Overlap present.\n");
	} else {
		printf("Overlap not present.\n");
	}
	
	return 0;
	
}