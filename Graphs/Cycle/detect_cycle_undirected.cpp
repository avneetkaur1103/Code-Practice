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
	bool dfs(int v, bool visited[],int parent);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::dfs(int v, bool visited[], int parent){
	visited[v] = true;

	list<int>::iterator it;
	for(it= adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it] && dfs(*it,visited,v))
			return true;
		else if(*it != parent)
			return true;
	}

	return false;
}

bool Graph::isCyclic(){
	bool *visited= new bool[V];
	for(int i=0; i<V;i++){
		visited[i] = false;
	}

	for(int i=0;i<V;i++){
		if(!visited[i])
			if(dfs(i,visited,-1))
				return true;
	} 
	return false;
}

int main(){
	Graph g(5); 
    g.addEdge(1,0); 
    g.addEdge(0,2); 
    g.addEdge(2,1); 
    g.addEdge(0,3); 
    g.addEdge(3,4);
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 

    cout<<endl;

    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2);

    if(g2.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 

    cout<<endl;
    return 0;
}

//complexity:O(V+E)