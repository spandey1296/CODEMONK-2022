/* Program for creation of Graph through adjacency matrix */
/* Data Structures Using C by UDIT AGARWAL */
#include<stdio.h>
#include<conio.h>
#define max 20

int adj[max][max]; 
int n;    
void main()
{
	int max_edges,i,j,origin,dest;
	char type;
	clrscr();
	printf("Enter number of nodes in graph: ");
	scanf("%d",&n);
	printf("Enter type of graph, directed or undirected (d/u) : ");
	fflush(stdin);
	scanf("%c",&type);

	if(type=='u')
		max_edges=n*(n-1)/2;
	else
		max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d( 0 0 to Quit ) : ",i);
		scanf("%d %d",&origin,&dest);
		if( (origin==0) && (dest==0) )
			break;
		if( origin > n || dest > n || origin<=0 || dest<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
		{
			adj[origin][dest]=1;
			if(type=='u')
				adj[dest][origin]=1;
		}
	}

	printf("The adjacency matrix of graph is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
getch();
}

