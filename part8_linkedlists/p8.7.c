//delete kth node from the end
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
	
void deleteKth(struct node* head, int k) {
	struct node *p, *q;
	p = head;
	q = head;
	while(k>0) {
		p = p->next;
		k--;
	}
	while(p->next != NULL) {
		q = q->next;
		p = p->next;
		
	}
	q->next = q->next->next;
	//free(q)
}
	
int main() {
	struct node* head = NULL;
	insertLast(&head, 1);
	insertLast(&head, 2);
	insertLast(&head, 3);
	insertLast(&head, 4);
	insertLast(&head, 5);
	printf("Enter value of k: ");
	int k;
	scanf("%d", &k);
	traverse(head);
	deleteKth(head, k);
	traverse(head);
	return 0;
}