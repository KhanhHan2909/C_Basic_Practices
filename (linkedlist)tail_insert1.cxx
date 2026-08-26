#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node *tiep;
};

void duyet_va_in(node *head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->tiep;//Cho head chuyen sang node ke tiep
	}
}

void themcuoi(node **head,int x)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->tiep = NULL;
	if(*head==NULL)
	{
		*head = newnode;
		return;
	}
	node *temp = *head;
	while(temp->tiep!=NULL)
		temp = temp-> tiep;
	temp->tiep = newnode;
}

int main(void)
{
	int i;
	node *head = NULL;
	for(i=1;i<11;i++) themcuoi(&head,i);
	duyet_va_in(head);
}