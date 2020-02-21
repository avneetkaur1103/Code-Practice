#include <iostream>
using namespace std;

struct Edge{
	int src, dest;
};

struct Graph{
	int V;
	int E;
	struct Edge *edges;
};

Graph* createGraph(int V, int E){
	Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edges = new Edge[g->E * sizeof(Edge)];
	return g;
}

int find(int parent[], int i){
	if(parent[i] == -1)
		return i;

	return find(parent,parent[i]);
} 

void _union(int x, int y, int parent[]){
	int u = find(parent,x);
	int v = find(parent,y);
	if(u!=v)
		parent[u] = v;
}

bool isCycle(Graph *graph){
	int *parent = new int[graph->V];
	for(int i=0;i<graph->V;i++)
		parent[i] = -1;

	for(int i=0;i<graph->E;i++){
		int x = find(parent,graph->edges[i].src);
		int y = find(parent,graph->edges[i].dest);

		if(x == y)
			return true;

		_union(x,y,parent);
	}
	return false;
}

int main(){
	int V = 3, E = 3;  
    Graph* graph = createGraph(V, E);  
 
    graph->edges[0].src = 0;  
    graph->edges[0].dest = 1;
    graph->edges[1].src = 1;  
    graph->edges[1].dest = 2;  
    graph->edges[2].src = 0;  
    graph->edges[2].dest = 2;  
  
    if (isCycle(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";  
  
    return 0;  
}

//Complexity: O(n)