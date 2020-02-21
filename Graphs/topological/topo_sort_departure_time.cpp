#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, vector<bool> &visited, vector<int> &departure, int &time);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v,vector<bool> &visited, vector<int> &departure, int &time){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it!= adj[v].end();it++){
		if(!visited[*it])
			topologicalSortUtil(*it,visited,departure,time);
	}
	departure[++time] = v;
}

void Graph::topologicalSort(){
	vector<bool> visited(V,false);
	vector<int> departure(V,-1);

	int time = -1;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,departure,time);
	}

	for(int i = V-1;i>=0;i--)
		cout<<departure[i]<<" ";
	
}

int main(){
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topologicalSort();
    return 0;
}

//Complexity: O(V+E) (DFS)