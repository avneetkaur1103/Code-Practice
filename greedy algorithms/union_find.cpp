#include <iostream>
#include <string.h>


using namespace std;

struct Edge{
	int src, dest;
};

struct Graph{
	int E, V;
	struct Edge *edges;
};

struct Graph* create_graph(int V, int E){
	Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	
	graph->edges = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
	return graph;
}

int find(int parent[], int i){
	if (parent[i] == -1)
		return i;
	else
		find(parent,parent[i]);
}

void _union(int parent[], int u,int v){
	int u_p = find(parent, u);
	int v_p = find(parent, v);
	if (u_p != v_p)
		parent[u_p] = v_p;
}

bool iscycle(Graph *g){
	int *parent = (int*)malloc(g->V * sizeof(int));
	memset(parent, -1, g->V * sizeof(int));
	
	for (int i =0; i < g->E; i++){
		int x = find(parent, g->edges[i].src);
		int y = find(parent, g->edges[i].dest);
		
		if(x != y)
			_union(parent,g->edges[i].src, g->edges[i].dest);
		else
			return true;
	}
	
	return false;
}

int main() {
	
	int V=4;
	int E=3;
	struct Graph *graph = create_graph(4,3);
	graph->edges[0].src = 0;
	graph->edges[0].dest = 1;
	graph->edges[1].src = 1;
	graph->edges[1].dest = 2;
	graph->edges[2].src = 2;
	graph->edges[2].dest = 3;
	
	if(iscycle(graph))
		cout<<"Cycle found";
	else
		cout<<"No cycle is present";
	return 0;
}

//Complexity:O(n)