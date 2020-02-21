#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCyclic();
	bool dfs(int v, bool visited[],bool reStack[]);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

bool Graph::dfs(int v, bool visited[], bool reStack[]){
	visited[v] = true;
	reStack[v] = true;

	list<int>::iterator it;
	for(it= adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it] && dfs(*it,visited,reStack))
			return true;
		else if(reStack[*it])
			return true;
	}
	
	reStack[v] = false;
	return false;
}

bool Graph::isCyclic(){
	bool visited[V];
	bool reStack[V];
	for(int i=0; i<V;i++){
		visited[i] = false;
		reStack[i] = false;
	}

	for(int i=0;i<V;i++){
		if(!visited[i])
			if(dfs(i,visited,reStack))
				return true;
	} 
	return false;
}

int main(){
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;
}

//complexity:O(V+E)