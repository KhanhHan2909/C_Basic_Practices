#include<stdio.h>
#include<stdlib.h>

struct ps
{
	int tuso;
	int mauso;
	ps *next;
};

struct list
{
	ps *head;
	ps *tail;
};

ps* makenode(ps *node,int x,int y)
{
	if(node==NULL)
		return NULL;
	node = (ps*)malloc(sizeof(ps));
	node->tuso = x;
	node->mauso = y;
	node->next = NULL;
	return node;
}

int main()
{
	ps *node = NULL;
	int x, y;
	printf("Nhap tu: ");
	scanf("%d",&x);
	do
	{
		printf("Nhap mau: ");
		scanf("%d",&y);
	} while(y==0);
	makenode(node,x,y);
}