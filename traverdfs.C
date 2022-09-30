/* Program for traversing a graph through DFS */
/* Data Structures Using C by UDIT AGARWAL */
#include<stdio.h>
#include<conio.h>
#define MAX 20

typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;
void main()
{
	int i,v,choice;
	clrscr();

	printf("\n\tTraversing of a graph through DFS\n");
	printf("\t**********************************\n\n");
	create_graph();
	while(1)
	{
		printf("\n");
		printf("1. Adjacency matrix\n");
		printf("2. Depth First Search using stack\n");
		printf("3. Depth First Search through recursion\n");
		printf("4. Number of components\n");
		printf("5. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Adjacency Matrix is \n");
			display();
			break;

		 case 2:
			printf("Enter starting node:  ");
			scanf("%d",&v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			dfs(v);
			break;

		 case 3:
			printf("Enter starting node:  ");
			scanf("%d",&v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			dfs_rec(v);
			break;

		 case 4:
			 printf("Components are ");
			 components();
		     break;

		 case 5:
			exit(1);

		 default:
			printf("Enter correct choice\n");
			break;
		 }
	}
}

create_graph()
{
	int i,max_edges,origin,dest;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( 0 0 to quit ) : ",i);
		scanf("%d %d",&origin,&dest);

		if((origin==0) && (dest==0))
			break;

		if( origin > n || dest > n || origin<=0 || dest<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][dest]=1;
		}
	}
return 0;
}

display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
return 0;
}


dfs_rec(int v)
{
	int i;
	visited[v]=true;
	printf("%d ",v);
	for(i=1;i<=n;i++)
		if(adj[v][i]==1 && visited[i]==false)
			dfs_rec(i);
return 0;
}

dfs(int v)
{
	int i,stack[MAX],top=-1,pop_v,j,t;
	int  ch;

	top++;
	stack[top]=v;
	while (top>=0)
	{
		pop_v=stack[top];
		top--;                      /*pop from stack*/
		if( visited[pop_v]==false)
		{
			printf("%d ",pop_v);
			visited[pop_v]=true;
		}
		else
			continue;

		for(i=n;i>=1;i--)
		{
			if( adj[pop_v][i]==1 && visited[i]==false)
			{
				top++;    /* push all unvisited neighbours of pop_v */
				stack[top]=i;
			}
		}
	}
return 0;
}

components()
{
	int i;
	for(i=1;i<=n;i++)
		visited[i]=false;
	for(i=1;i<=n;i++)
	{
		if(visited[i]==false)
			dfs_rec(i);
	}
	printf("\n");
return 0;
}
