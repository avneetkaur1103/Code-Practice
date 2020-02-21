#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool isCyclic(int v, bool visited[], int parent);

public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isTree();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCyclic(int v,bool visited[],int parent){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it]){
			if(isCyclic(*it,visited,v))
				return true;
		}
		else if(*it != parent)
				return true;
	}
	return false;
}

bool Graph::isTree(){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	if(isCyclic(0,visited,-1))
		return false;

	for(int i=0;i<V;i++)
		if(!visited[i])
			return false;

	return true;
}

int main(){
	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n";
    return 0;
}