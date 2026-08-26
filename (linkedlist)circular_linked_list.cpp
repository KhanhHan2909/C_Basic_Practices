#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	node* next;
};

node* initlist()
{
	node* head = (node*)malloc(sizeof(node));
	if(head==NULL)
	{
		printf("Khong khoi tao duoc danh sach!");
		exit(1);
	}
	head->next = head;
	return head;
}

node* createnode(int x)
{
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode==NULL) 
	{
        printf("Khong cap phat duoc bo nho\n");
        exit(1);
    }
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void  insertfirst(node* head,int x)
{
	node* p = createnode(x);
	p->next = head->next;
	head->next = p;
}

void insertlast(node* head,int x)
{
	node* p = createnode(x);
	node* temp = head;
	while(temp->next!=head) temp = temp->next;
	temp->next = p;
	p->next = head;
}

void printlist(node* head)
{
	printf("(head)");
	node* temp = head;
	while(temp->next!=head)
	{
		temp = temp->next;
		printf(" -> %d",temp->data);
	}
}

int main()
{
	node* head = initlist();
	insertfirst(head,3);
	insertfirst(head,4);
	insertlast(head,5);
	insertlast(head,6);
	printlist(head);
}