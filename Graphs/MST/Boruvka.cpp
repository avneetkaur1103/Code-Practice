#include <iostream>
using namespace std;

struct Edge{
	int src, dest,weight;
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

void boruvkaMST(Graph *g){
	int numOfTrees = g->V;
	int minSpanTreeWeight = 0;

	struct Subset *s = new Subset[g->V];
	int *cheapest = new int[g->V];

	for(int i=0;i<g->V;i++){
		s[i].parent = i;
		s[i].rank = 0;
		cheapest[i] = -1;
	}

	while(numOfTrees > 1){
		//cout<<"Num of trees: "<<numOfTrees<<endl;

		for(int i=0;i<g->V;i++)
			cheapest[i] = -1;

		for(int i=0;i<g->E;i++){
			int x = find(s, g->edges[i].src);
			int y = find(s, g->edges[i].dest);

			if(x == y)
				continue;
			else{
				if(cheapest[x] == -1 || g->edges[cheapest[x]].weight > g->edges[i].weight)
					cheapest[x] = i;

				if(cheapest[y] == -1 || g->edges[cheapest[y]].weight > g->edges[i].weight)
					cheapest[y] = i;
			}
		
		}

		for(int i=0;i<g->V;i++){
			if(cheapest[i] != -1){
				int x = find(s, g->edges[cheapest[i]].src);
				int y = find(s, g->edges[cheapest[i]].dest);

				if(x==y)
					continue;

				minSpanTreeWeight += g->edges[cheapest[i]].weight;

				cout<<"Source: "<<g->edges[cheapest[i]].src<<" and Destination: "<<g->edges[cheapest[i]].dest<<endl;
				_union(s,x,y);
				numOfTrees--;
			}
		}
	}
	cout<<"minSpanTreeWeight: "<<minSpanTreeWeight<<endl;
	return;
}

int main(){
	int V = 4, E = 5; 
    struct Graph* graph = createGraph(V, E); 
  
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0; 
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1; 
    graph->edges[3].dest = 3; 
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2; 
    graph->edges[4].dest = 3; 
    graph->edges[4].weight = 4;
  
    boruvkaMST(graph);

    return 0;
}

//Complexity: O(ElogV)