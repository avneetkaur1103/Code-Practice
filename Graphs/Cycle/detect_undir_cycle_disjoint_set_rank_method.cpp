#include <iostream>
using namespace std;

struct Edge{
	int src, dest;
};

struct Graph{
	int V, E;
	Edge *edges;
};

struct Subset{
	int parent;
	int rank;
};

Graph* createGraph(int V, int E){
	Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edges = new Edge[g->E * sizeof(struct Edge)];
	return g;
}

int find(Subset s[], int i){
	if(s[i].parent != i)
		return find(s,s[i].parent);
}

void _union(Subset s[], int x, int y){
	int u = find(s,u);
	int v = find(s,y);

	if(s[u].rank > s[v].rank)
		s[v].parent = u;
	else if (s[u].rank < s[v].rank)
		s[u].parent = v;
	else{
		s[v].parent = u;
		s[u].rank++;
	}
}

bool isCycle(Graph *g){
	struct Subset *s = (struct Subset*) malloc(g->V * sizeof(struct Subset));

	for(int i=0;i<g->V;i++){
		s[i].parent = i;
		s[i].rank = 0;
	}

	for(int i=0;i<g->E;i++){
		int x = find(s, g->edges[i].src);
		int y = find(s, g->edges[i].dest);

		if(x == y)
			return 1;

		_union(s,x,y);
	}
	return 0;
}

int main(){
	int V = 3, E = 3; 
    struct Graph* graph = createGraph(V, E); 
  
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 

    graph->edges[1].src = 1; 
    graph->edges[1].dest = 2; 

    graph->edges[2].src = 0; 
    graph->edges[2].dest = 2; 
  
    if (isCycle(graph)) 
        printf( "Graph contains cycle" ); 
    else
        printf( "Graph doesn't contain cycle" ); 
  
    return 0;
}

//Complexity: O(logn)