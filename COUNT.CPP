/* Program to find no. of nodes and leaves in the BST */
/* Data Structures Using C by UDIT AGARWAL */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
long value;
struct node *left;
struct node *right;
};
struct node *tree=NULL;
struct node *insert(struct node *tree,long value);
void countnode(struct node *tree);
void countleave(struct node *tree);
select();
struct node *temp;
int node=1,total=0;

void main()
{
clrscr();
struct node *tree=NULL;
int choice;
long digit;
do
{
choice=select();
switch(choice)
{
case 1: puts("Enter integers:To quit enter 0");
scanf("%ld",&digit);
while(digit!=0)
{
tree=insert(tree,digit);
scanf("%ld",&digit);
}continue;
case 2: countnode(tree);
printf("Number of nodes=%d\n",node);
continue;
case 3: countleave(tree);
printf("Number of leaves=%d\n",total);
continue;
case 4: puts("END");
exit(0);
}
}while(choice!=4);
}
int select()
{
int selection;
do
{
puts("Enter 1: Insert a node");
puts("Enter 2: Display Number of nodes");
puts("Enter 3: Display Number of leave");
puts("Enter 4: End");
puts("Enter your choice");
scanf("%d",&selection);
if((selection<1)||(selection>4))
{
puts("Wrong choice: Try again");
getchar();
}
}while((selection<1)||(selection>4));
return selection;
}
struct node *insert(struct node *tree,long digit)
{
if(tree==NULL)
{
tree=(struct node *)malloc(sizeof(struct node ));
tree->left=tree->right=NULL;
tree->value=digit;
}
else
if(digit<tree->value)
tree->left=insert(tree->left,digit);
else
if(digit>tree->value)
tree->right=insert(tree->right,digit);
else
if(digit==tree->value)
{
puts("Duplicates Nodes:Program Exited");
getch();
exit(0);
}
return(tree);
}
void countnode(struct node *tree)
{
if(tree!=NULL)
{
if(tree->left!=NULL)
{
node++;
countnode(tree->left);
}
if(tree->right!=NULL)
{
node++;
countnode(tree->right);
}
}
}
void countleave(struct node *tree)
{
  if(tree!=NULL)
	{
      if((tree->left==NULL)&&(tree->right==NULL))
	total++;
else
    {
     countleave(tree->left);
     countleave(tree->right);
     }
  }
}
