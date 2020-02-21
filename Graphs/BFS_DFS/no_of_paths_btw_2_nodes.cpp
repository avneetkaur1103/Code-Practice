#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(bool visited[], int s, int d, int &pathCount );

	public:
		Graph(int V);
		void addEdge(int v, int w);
		int DFS(int s, int d);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(bool visited[], int s, int d, int &pathCount){
	visited[s] = true;
	
	if(s == d)
		pathCount++;

	list<int>::iterator it;

	for(it = adj[s].begin(); it != adj[s].end(); it++){
		if(!visited[*it])
			DFSUtil(visited, *it, d, pathCount);
	}
	visited[s] = false;
}

int Graph::DFS(int s, int d){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	int pathCount = 0;
	DFSUtil(visited,s,d,pathCount);
	return pathCount;
}

int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(2,0);
	g.addEdge(2,1);
	g.addEdge(1,3);
	int s=2, d=3;
	cout<<g.DFS(s,d);
	return 0;
}

//Complexity: O(V+E)