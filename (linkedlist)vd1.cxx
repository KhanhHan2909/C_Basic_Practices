#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

int main()
{
	node *head = (node*)malloc(sizeof(node));
	head->data = 10;
	head->next = NULL;
	node *nn = (node*)malloc(sizeof(node));
	nn->data = 5;
	nn->next = head; //gia tri cua next phai gan cho kieu du lieu node
	printf("%d",nn->data);
	nn = nn->next;
	printf("\n%d",nn->data);
	//printf("Gia tri cua head: %d",head);
//	printf("\nDu lieu ma head quan ly: %d",head->data);
}