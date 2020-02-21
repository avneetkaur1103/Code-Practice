#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(vector<bool> &visited, int v );

	public:
		Graph(int V);
		void addEdge(int v, int w);
		int countTrees();
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(vector<bool> &visited, int i){
	visited[i] = true;

	list<int>::iterator it;
	for(it = adj[i].begin(); it != adj[i].end(); it++){
		if(!visited[*it])
			DFSUtil(visited, *it);
	}
}

int Graph::countTrees(){
	vector<bool> visited(V,false);
	int res = 0;

	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFSUtil(visited,i);
			res++;
		}
	}

	return res;
}

int main(){
	Graph g(5);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(3, 4);
    cout<<g.countTrees();
    return 0;
}

//Complexity: O(V+E)