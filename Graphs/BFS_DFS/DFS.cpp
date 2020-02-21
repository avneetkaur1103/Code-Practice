#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(bool visited[], int v );

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void DFS(int s);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(bool visited[], int u){
	visited[u] = true;
	cout<<u<<" ";

	list<int>::iterator it;

	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(!visited[*it])
			DFSUtil(visited, *it);
	}
}

void Graph::DFS(int u){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	DFSUtil(visited,u);
}

//If we have  disconnected graphs, then we need to call DFSUtil in loop in DFS() . for(all vertices) call DFSUtil() */

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.DFS(2);
	return 0;
}

//Complexity: O(V+E)