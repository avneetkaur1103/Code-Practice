#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int *in;
	bool isConnected();
	void DFS(int v, bool visited[]);
	bool isSSC();
	Graph getTranspose();
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isEulerian();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
}
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	in[v]++;
}

void Graph::DFS(int v, bool visited[]){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++)
		if(!visited[*it])
			DFS(*it,visited);
}

Graph Graph::getTranspose(){
	Graph g(V);
	for(int i=0;i<V;i++){
		list<int>::iterator it;
		for(it= adj[i].begin(); it != adj[i].end(); it++){
			g.adj[*it].push_back(i);
			g.in[i]++;
		}
	}
	return g;
}

bool Graph::isSSC(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	int n;
	for(int i=0;i<V;i++){
		if(adj[i].size() > 0){
			n = i;
			break;
		}
	}

	DFS(n,visited);

	for(int i=0;i<V;i++){
		if(!visited[i] && adj[i].size()>0)
			return false;
	}

	Graph gT = getTranspose();

	for(int i=0;i<V;i++)
		visited[i] = false;

	gT.DFS(n,visited);

	for(int i=0;i<V;i++){
		if(!visited[i] && adj[i].size()>0)
			return false;
	}

	return true;
}

bool Graph::isEulerian(){
	if(!isSSC())
		return false;

	for(int i=0;i<V;i++){
		if(adj[i].size() != in[i])
			return false;
	}
	return true;
}

int main(){
	Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0); 
  
    if (g.isEulerian())
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;

    return 0;
}

//Complexity: O(V+E)