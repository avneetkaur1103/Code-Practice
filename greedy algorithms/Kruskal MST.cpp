#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Edge{
	int src, dest, weight;
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

int comp_fn(const void *a, const void *b){
	struct Edge *e_a = (struct Edge *)a;
	struct Edge *e_b = (struct Edge *)b;
	
	return e_a->weight > e_b->weight;
}

void KruskalMST(Graph *g){
	
	int V = g->V;
	struct Edge result[V-1];

	int j=0, e=0;
	struct subset *s = (struct subset*)malloc(g->V * sizeof(struct subset));
	for(int i=0; i<V; i++){
		s[i].parent = i;
		s[i].rank = 0;
	}
	qsort(g->edges, g->E, sizeof(g->edges[0]), comp_fn);
	
	while(e<V-1){
		struct Edge next_edge = g->edges[j++];
		int x = find(s, g->edges[j].src);
		int y = find(s, g->edges[j].dest);
		
		if(x != y){
			result[e++] = next_edge;
			_union(s, g->edges[j].src, g->edges[j].dest);
		}
		
	}
	
	for (int i=0; i<e; i++){
			cout<<result[i].src <<"  |  "<<result[i].dest<<"  |  "<<result[i].weight<<endl;
		}
}

int main() {
	
	int V=3;
	int E=3;
	struct Graph *graph = create_graph(3,3);
	graph->edges[0].src = 0;
	graph->edges[0].dest = 1;
	graph->edges[0].weight = 5;
	graph->edges[1].src = 1;
	graph->edges[1].dest = 2;
	graph->edges[1].weight = 14;
	graph->edges[2].src = 2;
	graph->edges[2].dest = 0;
	graph->edges[2].weight =7;
	KruskalMST(graph);
	
	return 0;
}

//Complexity: O(ELogE (sort) + E * logV(union find on each edge))