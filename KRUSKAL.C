/* Creating a MST from Kruskal's algorithm */
/* Data Structures Using C by UDIT AGARWAL */

#include<stdio.h>
#include<conio.h>
#define MAX 20

struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front = NULL;

int parent[MAX]; /*Holds parent of each node */
struct edge tree[MAX]; /* Will contain the edges of spanning tree */
int n;   /*Denotes total number of nodes in the graph */
int wt=0; /*Weight of the spanning tree */
int count=0;    /* Denotes number of edges included in the tree */


void make_tree();
void insert_tree(int i,int j,int wt);
void insert_pque(int i,int j,int wt);
struct edge *del_pque();

void main()
{

	int i;
	clrscr();
	printf("\n\t MST from Kruskal's algorithm \n");
	printf("\t**************************\n\n");
	create_graph();
	make_tree();
	printf("\nEdges to be included in spanning tree are :\n");
	for(i=1;i<=count;i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
	}
	printf("\n Weight of this MST is : %d\n", wt);
	getch();
}

create_graph()
{
	int i,wt,max_edges,origin,dest;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=(n*(n-1))/2;
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&dest);
		if( (origin==0) && (dest==0) )
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if( origin > n || dest > n || origin<=0 || dest<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			insert_pque(origin,dest,wt);
	}
	if(i<n-1)
	{
		printf("Spanning tree is not possible\n");
		exit(1);
		}
return 0;
}

void make_tree()
{
	struct edge *tmp;
	int node1,node2,root_n1,root_n2;

	while( count < n-1) /*Loop till n-1 edges included in the tree*/
	{
		tmp=del_pque();
		node1=tmp->u;
		node2=tmp->v;

		printf("n1=%d  ",node1);
		printf("n2=%d  ",node2);

		while( node1 > 0)
		{
			root_n1=node1;
			node1=parent[node1];
		}
		while( node2 >0 )
		{
			root_n2=node2;
			node2=parent[node2];
		}
		printf("rootn1=%d  ",root_n1);
		printf("rootn2=%d\n",root_n2);

		if(root_n1!=root_n2)
		{
		      insert_tree(tmp->u,tmp->v,tmp->weight);
		      wt=wt+tmp->weight;
		      parent[root_n2]=root_n1;
		}
	}
}

void insert_tree(int i,int j,int wt)
{
	printf("This edge inserted in the spanning tree\n");
	count++;
	tree[count].u=i;
	tree[count].v=j;
	tree[count].weight=wt;
}


void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;

	tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->u=i;
	tmp->v=j;
	tmp->weight = wt;

	/*Queue is empty or edge to be added has weight less than first edge*/
	if( front == NULL || tmp->weight < front->weight )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->weight <= tmp->weight )
			q=q->link;
		tmp->link = q->link;
		q->link = tmp;
		if(q->link == NULL)
			tmp->link = NULL;
	}
}


struct edge *del_pque()
{
	struct edge *tmp;
	tmp = front;
	printf("\nEdge selected is %d->%d and weight is %d\n",tmp->u,tmp->v,tmp->weight);
	front = front->link;
	return tmp;
}


