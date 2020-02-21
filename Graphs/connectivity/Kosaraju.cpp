#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list <int> *adj;
	void DFS(int v, bool visited[]);
	Graph transposeGraph();
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isSC();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::DFS(int s, bool visited[]){
	visited[s] = true;
	list<int>::iterator it;
	for(it = adj[s].begin();it != adj[s].end(); it++){
		if(!visited[*it])
			DFS(*it,visited);
	}
}

Graph Graph::transposeGraph(){
	Graph g(V);
	for(int i=0;i<V;i++){
		list<int>::iterator it;
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			g.addEdge(*it,i);
		}
	}
	return g;
}

bool Graph::isSC(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	DFS(0,visited);

	for(int i=0;i<V;i++)
		if(!visited[i])
			return false;

	Graph g1 = transposeGraph();

	for(int i=0;i<V;i++)
		visited[i] = false;

	g1.DFS(0,visited);

	for(int i=0;i<V;i++)
		if(!visited[i])
			return false;

	return true;
}

int main(){
	Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(1, 2); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 0); 
    g1.addEdge(2, 4); 
    g1.addEdge(4, 2); 
    g1.isSC()? cout << "Yes\n" : cout << "No\n"; 

    Graph g2(4); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.addEdge(2, 3); 
    g2.isSC()? cout << "Yes\n" : cout << "No\n"; 
    return 0;
}

//Complexity: O(V+E)