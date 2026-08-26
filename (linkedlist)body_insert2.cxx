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

node* themdau(node *head,node *middle)
{
	middle->tiep = head;
	head = middle;
	return head;
}

node* themcuoi(node *head,int x)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->tiep = NULL;
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	node *temp = head;
	while(temp->tiep!=NULL)
		temp = temp-> tiep;
	temp->tiep = newnode;
	return head;
}

node* themgiua(node *head,node *middle2,node *middle,int k)
{
	int i = 2;
	node *temp = head;
	while(i<k) 
	{
		temp = temp->tiep;
		i++;
	}
	temp->tiep = middle;
	middle->tiep = middle2;
	return head;
}

int main(void)
{
	int i, j, x, k;
	node *head = NULL, *middle, *middle2 = NULL;
	for(i=1;i<11;i++) head = themcuoi(head,i);
	duyet_va_in(head);
	printf("\nNhap gia tri can chen: ");
	scanf("%d",&x);
	printf("Nhap vi tri chen: ");
	scanf("%d",&k);
	middle = (node*)malloc(sizeof(node));
	middle->data = x;
	middle->tiep = NULL;
	if(k==1) head = themdau(head,middle);
	else
	{
		for(j=k;j<i;j++) middle2 = themcuoi(middle2,j);
		head = themgiua(head,middle2,middle,k);
	}
	duyet_va_in(head);
}