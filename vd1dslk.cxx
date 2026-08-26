#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int data;
	node *next;
};

typedef struct node node;

int main(void)
{
	node *head = (node*)malloc(sizeof(node));
	head -> data = 100;
	head -> next = NULL;
	printf("Gia tri cua head: %d\n",head);
	printf("Du lieu node ma head quan ly: %d\n",head->data);
}