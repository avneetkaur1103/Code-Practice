#include <iostream>
#include <list>
using namespace std;

enum Color {WHITE, GRAY, BLACK}; 

class Graph{
	int V;
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCyclic();
	bool dfs(int v, int color[]);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

bool Graph::dfs(int v, int color[]){
	color[v] = GRAY;

	list<int>::iterator it;
	for(it= adj[v].begin(); it != adj[v].end(); it++){
		if(color[*it] == WHITE && dfs(*it,color))
			return true;
		if(color[*it] == GRAY)
			return true;
	}
	
	color[v] = BLACK;
	return false;
}

bool Graph::isCyclic(){
	int color[V];
	
	for(int i=0; i<V;i++){
		color[i] = WHITE;
	}

	for(int i=0;i<V;i++){
		if(color[i] == WHITE)
			if(dfs(i,color))
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