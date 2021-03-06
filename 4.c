#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 100
#define true 1
int visited[MAXVEX]={0};
typedef char VertexType;
typedef int EdgeType;
typedef struct EdgeNode  /*边表结点*/
{
	int adjvex;	//存储顶点下标
	EdgeType weight;
	struct EdgeNode* next;
}EdgeNode;
typedef struct VertexNode	/*顶点表节点*/
{
	VertexType data;
	EdgeNode* firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct
{
	AdjList adjList;
	int numVertexes,numEdges;
}GraphAdjList;
void CreatGraph(GraphAdjList *g);
void DFS(GraphAdjList *g,int i);
void DFSTravel(GraphAdjList *g);
int main()
{
	GraphAdjList g;
	CreatGraph(&g);
	DFSTravel(&g);
	return 0;
}
void CreatGraph(GraphAdjList *g)
{
	int i,j,k;
	EdgeNode *e;
	scanf("%d%d",&g->numVertexes,&g->numEdges);
	char c;
	//gettchar();
	for(i=0;i<g->numVertexes;i++)
	{
		while((c=getchar())=='\n'||c==' ');
		g->adjList[i].data = c;
		//	scanf("%c",&g->adjList[i].data);
				
		g->adjList[i].firstedge = NULL;
	}
	for(k=0;k<g->numEdges;k++)
	{
		scanf("%d%d",&i,&j);
		e=(EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = j;
		e->next = g->adjList[i].firstedge;
		g->adjList[i].firstedge= e;
                e=(EdgeNode*)malloc(sizeof(EdgeNode));
                e->adjvex = i;
                e->next = g->adjList[j].firstedge;
                g->adjList[j].firstedge= e;

	}
}
void DFS(GraphAdjList *g,int i)
{
	EdgeNode *p;
	visited[i]=1;
	printf("%c ",g->adjList[i].data);
	p = g->adjList[i].firstedge;
	while(p)
	{
		if(visited[p->adjvex]==0)
			DFS(g,p->adjvex);
		p=p->next;
	}
}
void DFSTravel(GraphAdjList *g)
{
	int i;
	for(i=0;i<g->numVertexes;i++)
	{
		if(!visited[i])
			DFS(g,i);	//主要是为了处理非连通图，如果为连通图,那么DFS函数执行一次即可遍历全部节点
	}
}

