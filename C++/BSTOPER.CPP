/* Implement Binary Search Tree with different operations */
/* Data Structures Using C by UDIT AGARWAL */

#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
int data;
struct bst *left, *right;
} node;

int insert(node *, node*);
int inorder(node *);
node *search(node *, int, node **);
int del(node *, int);

int main ( )
{
int ch;
char ans = 'N';
int key;
node *New, *root, *temp, *parent;
node *get_node( );
root=NULL;
printf("\n \t Program for Binary Search Tree");
do
{
printf("\n 1.Create \n 2.Search \n 3. Delete \n 4. Display");
printf("\n\n Enter your choice");
scanf("%d",&ch);
switch(ch)
{
case 1 : do
{
New=get_node( );
printf("\n Enter the Element");
scanf("%d",&New->data);
if(root==NULL)
root=New;
else
insert(root,New);
printf("\n Do u want to conitnue enter more elements(y/n)");
ans;
} while(ans=='N');
break;
case 2 :
printf("\n Enter the element which u want to search");
scanf("%d",&key);
temp=search(root,key,&parent);
printf("\n Parent of node %d is %d", temp->data,parent->data);
break;
case 3 : printf("\n Enter the Element u wish to delete");
scanf("%d",&key);
del(root,key);
break;
case 4 : if(root==NULL)
printf("Tree is not created");
else
{
printf("\n The tree is :");
inorder(root);
}
break;
}
} while (ch !=5);
}
node *get_node( )
{
node *temp;
temp=(node*)malloc(sizeof(node));
temp->left=NULL;
temp->right=NULL;
return temp;
}
int insert(node *root,node *New)
{
if(New->data<root->data)
{
if(root->left==NULL)
root->left=New;
else
insert(root->left,New);
}
if(New->data>root->data)
{
if(root->right==NULL)
root->right=New;
else
insert(root->right,New);
}
}
node *search(node *root,int key, node **parent)
{
node *temp;
temp=root;
while(temp !=NULL)
{
if(temp->data==key)
{
printf("\n The %d Element is present",temp->data);
return temp;
}
*parent=temp;
if(temp->data>key)
temp=temp->left;
else
temp=temp->right;
}
return NULL;
}
int del(node*root,int key)
{
node*temp,*parent,*temp_succ;
temp=search(root,key,&parent);
if(temp->left!=NULL&&temp->right!=NULL)
{
parent=temp;
temp_succ=temp->right;
while(temp_succ->left!=NULL)
{
parent=temp_succ;
temp_succ=temp_succ->left;
}
temp->data=temp_succ->data;
parent->right=NULL;
printf("\n Now deleted it!");
return 0;
}
if(temp->left!=NULL&&temp->right==NULL)
{
if(parent->left==temp)
parent->left=temp->left;
else
parent->right=temp->left;
temp=NULL;
free(temp);
printf("\n Now deleted it!");
return 0;
}
if(temp->left==NULL&&temp->right!=NULL)
{
if(parent->left==temp)
parent->left=temp->right;
else
parent->right=temp->right;
temp=NULL;
free(temp);
printf("\n Now deleted it!");
return 0;
}
if(temp->left==NULL &&temp->right==NULL)
{
if(parent->left==temp)
parent->right=NULL;
else
parent->right=NULL;
printf("\n Now Deleted it!");
return 0;
}
}
int inorder(node *temp)
{
if(temp !=NULL)
{
inorder(temp->left);
printf("%d", temp->data);
inorder(temp->right);
}
}
