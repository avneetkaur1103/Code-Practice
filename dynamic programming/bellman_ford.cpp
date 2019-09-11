#include <iostream>
#include <climits>
using namespace std;

struct Edge{
	int src, dest, wt;
};

struct Graph{
	int V, E;
	struct Edge *edges;
};

struct Graph* createGraph(int V, int E){
	struct Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edges = new Edge[E];
	return g;
}

void print(int dist[], int n){
	for (int i=0;i<n;i++){
		cout<<i<< "  "<<dist[i]<<endl;
	}
}

void bellman_ford(struct Graph *g){
	int V = g->V;
	int E = g->E;
	int dist[V];
	int i,j;
	for (i=0;i<V;i++){
		dist[i] = INT_MAX;
	}
	dist[0] = 0;
	
	for(i=0;i<V;i++){
		for (j=0;j<E;j++){
			int u = g->edges[j].src;
			int v = g->edges[j].dest;
			int w = g->edges[j].wt;
			if(dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}
	
	for (i=0;i<E;i++){
		int u = g->edges[j].src;
		int v = g->edges[j].dest;
		int w = g->edges[j].wt;
		if(dist[u] != INT_MAX && dist[u] + w < dist[v])
			cout<<"Negative Cycle detected";
	}
	print(dist, V);
	return;
}

int main() {
	int V = 5; 
    int E = 8;
    struct Graph* graph = createGraph(V, E); 
  
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 
    graph->edges[0].wt = -1; 
  

    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].wt = 4; 
  
    
    graph->edges[2].src = 1; 
    graph->edges[2].dest = 2; 
    graph->edges[2].wt = 3; 
  
     
    graph->edges[3].src = 1; 
    graph->edges[3].dest = 3; 
    graph->edges[3].wt = 2; 
  
    
    graph->edges[4].src = 1; 
    graph->edges[4].dest = 4; 
    graph->edges[4].wt = 2; 
  
    
    graph->edges[5].src = 3; 
    graph->edges[5].dest = 2; 
    graph->edges[5].wt = 5; 
  
     
    graph->edges[6].src = 3; 
    graph->edges[6].dest = 1; 
    graph->edges[6].wt = 1; 
  
    
    graph->edges[7].src = 4; 
    graph->edges[7].dest = 3; 
    graph->edges[7].wt = -3; 
    
    bellman_ford(graph);
    
	return 0;
}


//Complexity:O(VE)