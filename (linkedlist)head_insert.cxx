#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *tiep;
};

void duyet(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->tiep;//Cho head chuyen sang node ke tiep
	}
}

void themdau(node **head,int x)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->tiep = NULL;
	newnode->tiep = *head;
	*head = newnode;
}

int main(void)
{
	int i;
	node *head = NULL;
	for(i=1;i<11;i++) themdau(&head,i);
	duyet(head);
}