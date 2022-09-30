/* Program for traversing a graph through BFS */
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

	printf("\n\tTraversing of a graph through BFS\n");
	printf("\t**********************************\n\n");
	create_graph();
	while(1)
	{
		printf("\n");
		printf("1. Adjacency matrix\n");
		printf("2. Breadth First Search\n");
		printf("3. Adjacent vertices\n");
		printf("4. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Adjacency Matrix\n");
			display();
			break;

		 case 2:
			printf("Enter starting node for Breadth First Search : ");
			scanf("%d", &v);
			for(i=1;i<=n;i++)
				visited[i]=false;
			bfs(v);
			break;
		 case 3:
			printf("Enter node to find adjacent vertices : ");
			scanf("%d", &v);
			printf("Adjacent Vertices are : ");
			adj_nodes(v);
			break;
		 case 4:
			exit(1);
		 default:
			printf("Wrong choice\n");
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


bfs(int v)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;

	printf("%d ",v);
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;

	while(front<=rear)
	{
		v=que[front];	 /* delete from queue */
		front++;
		for(i=1;i<=n;i++)
		{
			/* Check for adjacent unvisited nodes */
			if( adj[v][i]==1 && visited[i]==false)
			{
				printf("%d ",i);
				visited[i]=true;
				rear++;
				que[rear]=i;
			 }
		}
	}
return 0;
}

adj_nodes(int v)
{
	int i;
	for(i=1;i<=n;i++)
	if(adj[v][i]==1)
		printf("%d ",i);
	printf("\n");
return 0;
}

