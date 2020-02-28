#include <iostream>
#include <climits	>
using namespace std;

struct Edge{
	int src, dest,weight;
};

struct Graph{
	int V, E;
	struct Edge *edge;
};

Graph* createGraph(int V, int E){
	struct Graph* g = new Graph;
	g->V = V;
	g->E = E;
	g->edge = new Edge[g->E];
	return g;
}


bool isNegCycleBellmanFord(struct Graph *g, int start){
	int v= g->V;
	int e = g->E;

	int dis[v];
	for(int i=0;i<v;i++)
		dis[i] = INT_MAX;

	dis[0] = 0;

	for(int i=1;i<v;i++){
		for(int j =0;j<e;j++){
			int u = g->edge[j].src;
			int w = g->edge[j].dest;
			int wt = g->edge[j].weight;

			if(dis[u] != INT_MAX && dis[u] + wt < dis[w])
				dis[w] = dis[u] + wt;
		}
	}

	for(int j =0;j<e;j++){
			int u = g->edge[j].src;
			int w = g->edge[j].dest;
			int wt = g->edge[j].weight;

			if(dis[u] != INT_MAX && dis[u] + wt < dis[w])
				return true;
	}
	return false;
}

int main(){
	int V = 5;
	int E = 8;
	Graph *graph = createGraph(V,E);
	graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    if (isNegCycleBellmanFord(graph, 0)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 
}