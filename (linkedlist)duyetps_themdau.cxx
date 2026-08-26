#include<stdio.h>
#include<stdlib.h>

struct ps
{
	int tuso;
	int mauso;
	ps *next;
};

void duyet(ps *node)
{
	while(node!=NULL)
	{
		printf("%d/%d ",node->tuso,node->mauso);
		node = node->next;
	}
}

ps* makenode(ps *node,int i)
{
	int x, y;
	ps *nn = (ps*)malloc(sizeof(ps));
	printf("Nhap tu ps %d: ",i);
	scanf("%d",&x);
	do
	{
		printf("Nhap mau ps %d: ",i);
		scanf("%d",&y);
	} while(y<=0);
	nn->tuso = x;
	nn->mauso = y;
	nn->next = node;
	node = nn;
	return node;
}
	
int main()
{
	ps *node = NULL;
	int i;
	for(i=1;i<4;i++)
		node = makenode(node,i);
	duyet(node);
}
	