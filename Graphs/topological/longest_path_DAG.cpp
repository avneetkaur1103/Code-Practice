#include <iostream>
#include <stack>
#include <vector>

#define NINF INT_MIN

using namespace std;

struct Edge{
	int src, dest, wt;
};

struct adjNode{
	int v, weight;
};

struct Graph{
	int V, E;
	struct Edge *edges;
};

adjNode* createAdjNode(int v, int weight){
	adjNode *node = new struct adjNode;
	node->v = v;
	node->weight = weight;
	return node;
}

Graph* createGraph(int V, int E){
	Graph *g = new Graph;
	g->V = V;
	g->E = E;
	g->edges = new Edge[g->E * sizeof(Edge)];
	return g;
}

void topologicalSortUtil(int u,bool visited[], stack<int> &s, vector<adjNode*> adj[] ){
	visited[u] = true;

	vector<adjNode*>::iterator it;
	for(it = adj[u].begin(); it!= adj[u].end();it++){
		adjNode* node = *it;
		if(!visited[node->v])
			topologicalSortUtil(node->v,visited,s,adj);
	}
	s.push(u);
}

void longestPath(int s, Graph* g){
	int V= g->V;

	bool *visited = new bool[V];
	int distance[V];

	vector<adjNode*> adj[V];
	for(int i=0;i<g->E;i++){
		adjNode *node = createAdjNode(g->edges[i].dest,g->edges[i].wt);
		adj[g->edges[i].src].push_back(node);
	}

	for(int i=0;i<V;i++){
		distance[i] = NINF;
		visited[i] = false;
	}

	distance[s] = 0;
	stack<int> st;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,st,adj);
	}

	while(!st.empty()){
		int u = st.top();
		cout<<"stack: "<<u<<endl;
		st.pop();

		
		if(distance[u] != NINF){
			for (int i = 1; i <= V - 1; i++){ 
       			for (int j = 0; j < g->E; j++){ 
					int u = g->edges[j].src; 
           			int v = g->edges[j].dest; 
           			int wt = g->edges[j].wt; 
            		if (distance[u] + wt > distance[v]) 
                		distance[v] = distance[u] + wt; 
        		} 
   			} 
		}
	}

	for (int i = 0; i < V; i++)  
        (distance[i] == NINF) ? cout << "INF " : cout << distance[i] << " "; 
      
    delete [] visited; 
}

int main(){
	int V = 6;
	int E = 10;
	Graph *graph = createGraph(V,E);
	graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 
    graph->edges[0].wt = 5; 

    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].wt = 3; 

    graph->edges[2].src = 1; 
    graph->edges[2].dest = 3; 
    graph->edges[2].wt = 6; 

    graph->edges[3].src = 1; 
    graph->edges[3].dest = 2; 
    graph->edges[3].wt = 2; 

    graph->edges[4].src = 2; 
    graph->edges[4].dest = 4; 
    graph->edges[4].wt = 4; 

    graph->edges[5].src = 2; 
    graph->edges[5].dest = 5; 
    graph->edges[5].wt = 2; 

    graph->edges[6].src = 2; 
    graph->edges[6].dest = 3; 
    graph->edges[6].wt = 7; 

    graph->edges[7].src = 3; 
    graph->edges[7].dest = 5; 
    graph->edges[7].wt = 1; 

    graph->edges[8].src = 3; 
    graph->edges[8].dest = 4; 
    graph->edges[8].wt = -1; 

	graph->edges[8].src = 4; 
    graph->edges[8].dest = 5; 
    graph->edges[8].wt = -2; 

    int s= 1;
    longestPath(s,graph);
	return 0;
}

//Complexity: O(V+E)
//Shortest path in DAG- same approach & same complexity, except below condition-
//	if (distance[u] + wt < distance[v]) 
//	             		distance[v] = distance[u] + wt; 