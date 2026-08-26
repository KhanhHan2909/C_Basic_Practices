#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int x)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

Node* insert(Node* root,int x)
{
    if(root==NULL)
        return createNode(x);
    if(x<root->data)
        root->left = insert(root->left,x);
    else if(x>root->data)
        root->right = insert(root->right,x);
    return root;
}

Node* search(Node* root,int x)
{
    if(root==NULL||root->data==x)
        return root;
    if(x<root->data)
        return search(root->left,x);
    return search(root->right,x);
}

Node* findMin(Node* root) 
{
    while(root->left!=NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root,int x) 
{
    if(root==NULL)
        return root;
    if(x<root->data) 
    {
        root->left = deleteNode(root->left,x);
    }
    else if(x>root->data) 
    {
        root->right = deleteNode(root->right,x);
    }
    else
    {
        // Đã tìm thấy node cần xóa
        // Trường hợp 1 & 2: 0 hoặc 1 con
        if (root->left==NULL) 
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL) 
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Trường hợp 3: 2 con
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

//Duoi day la phan xoa khong de quy
Node* findMinWithParent(Node* root,Node** parent) 
{
    *parent = NULL;
    while(root->left!=NULL)
    {
        *parent = root;
        root = root->left;
    }
    return root;
}

Node* deleteNodeIterative(Node* root,int x)
{
    Node *parent = NULL;
    Node *curr = root;
    // 1. Tìm node cần xóa
    while(curr!=NULL&&curr->data!=x)
    {
        parent = curr;
        if(x<curr->data) curr = curr->left;
        else curr = curr->right;
    }
    // Không tìm thấy
    if(curr==NULL) return root;
    // 2. Nếu node có 2 con
    if(curr->left!=NULL&&curr->right!=NULL)
    {
        Node *minParent = NULL;
        Node *minNode = findMinWithParent(curr->right,&minParent);
        curr->data = minNode->data;
		if(minParent==NULL)
		{
        curr->right = minNode->right;
        free(minNode);
        return root;
    	}
        parent = minParent;
        curr = minNode;
    }
    // 3. Node có 0 hoặc 1 con
    Node *child;
    if(curr->left!=NULL) child = curr->left;
    else child = curr->right;
	// Nếu xóa node gốc
    if(parent==NULL)
    {
        free(curr);
        return child;
    }
    // Nối lại cây
    if(parent->left==curr) parent->left = child;
    else parent->right = child;
    free(curr);
    return root;
}

void inorder(Node* root) 
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main() 
{
    Node* root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,45);
    insert(root,40);
    insert(root,60);
    insert(root,80);
    printf("Duyet inorder: ");
    inorder(root);
    int x = 40;
    if (search(root,x)) printf("\nTim thay %d trong cay", x);
    else printf("\nKhong tim thay %d", x);
    deleteNodeIterative(root,70);
    printf("\nSau khi xoa 70: ");
    inorder(root);
    /*deleteNode(root,70);
    printf("\nSau khi xoa 70: ");
    inorder(root);*/
}