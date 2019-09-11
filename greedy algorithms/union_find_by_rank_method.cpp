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

struct subset{
	int parent, rank;
};

struct Graph* create_graph(int V, int E){
	Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->E = E;
	
	graph->edges = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
	return graph;
}

int find(struct subset s[], int i){
	if (s[i].parent != i)
		return find(s,s[i].parent);
	
	return s[i].parent;
}

void _union(struct subset s[], int u,int v){
	int u_p = find(s, u);
	int v_p = find(s, v);
	if (s[u_p].rank <  s[v_p].rank)
		s[u_p].parent = v_p;
	else if (s[u_p].rank >  s[v_p].rank)
		s[v_p].parent = u_p;
	else{
		s[u_p].parent = v_p;
		s[v_p].rank++;
	}
}

bool iscycle(Graph *g){
	int V = g->V;
	struct subset *s = (struct subset*)malloc(g->V * sizeof(struct subset));
	for(int i=0; i<V; i++){
		s[i].parent = i;
		s[i].rank = 0;
	}
	
	for (int i =0; i < g->E; i++){
		int x = find(s, g->edges[i].src);
		int y = find(s, g->edges[i].dest);
		
		if(x != y)
			_union(s, g->edges[i].src, g->edges[i].dest);
		else
			return true;
	}
	
	return false;
}

int main() {
	
	int V=3;
	int E=3;
	struct Graph *graph = create_graph(3,3);
	graph->edges[0].src = 0;
	graph->edges[0].dest = 1;
	graph->edges[1].src = 1;
	graph->edges[1].dest = 2;
	graph->edges[2].src = 2;
	graph->edges[2].dest = 0;
	
	if(iscycle(graph))
		cout<<"Cycle found";
	else
		cout<<"No cycle is present";
	return 0;
}

//Complexity:O(logn)