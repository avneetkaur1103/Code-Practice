#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *edges;
	public:
		Graph(int v);
		void addEdge(int u, int v);
		void DFSUtility(int v, bool visited[]);
		void DFS(int e);
};

Graph::Graph(int v){
	this->V = v;
	edges = new list<int> [V];
}

void Graph::addEdge(int u, int v){
	edges[u].push_back(v);
}

void Graph::DFSUtility(int v, bool visited[]){
	visited[v] = true;
	cout<< v << "\t";
	list<int>::iterator it;
	
	for (it = edges[v].begin(); it != edges[v].end(); ++it){
		if (!visited[*it]){
			DFSUtility(*it, visited);
		}
	}
}

void Graph::DFS(int e){
	bool *visited = new bool [V];
	for (int i = 0; i < V; i++){
		visited[i] = false;
	}
	
	DFSUtility(e, visited);
}

int main() {
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    g.DFS(2);
	return 0;
}