#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *edges;
	
	public:
		Graph(int v);
		void addEdge(int u, int v);
		void BFS(int e);
};

Graph::Graph(int v){
	int V= v;
	edges = new list<int> [V];
}

void Graph::addEdge(int u, int v){
	edges[u].push_back(v);
}

void Graph::BFS(int e){
	bool *visited = new bool[V];
	for (int i=0; i<V; i++){
		visited[i] = false;
	}
	
	queue<int> queue;
	queue.push(e);
	visited[e] = true;
	list<int>::iterator it;

	while (!queue.empty()){
		e = queue.front();
		cout<< e << "\t";
		queue.pop();
		for(it= edges[e].begin(); it != edges[e].end(); ++it){
			if(!visited[*it]){
				visited[*it] = true;
				queue.push(*it);
			}
		}
	}
}
int main() {
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.BFS(2);
	return 0;
}