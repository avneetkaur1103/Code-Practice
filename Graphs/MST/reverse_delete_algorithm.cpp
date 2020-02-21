#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	vector<pair<int, pair<int, int> > > edges;
	void DFS(int v, bool *visited);
public:
	Graph(int V);
	void addEdge(int u, int v,int w);
	bool isConnected();
	void reverseDeleteMST();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v, int w){
	adj[u].push_back(v);
	adj[v].push_back(u);

	edges.push_back(make_pair(w, make_pair(u,v)));
}

void Graph::DFS(int v, bool *visited){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it])
			DFS(*it,visited);
	}
}

bool Graph::isConnected(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	DFS(0, 	visited);

	for(int i=0;i<V;i++){
		if(!visited[i])
			return false;
	}
	return true;
}

void Graph::reverseDeleteMST(){
	sort(edges.begin(), edges.end());
	int mstWt = 0;
	for(int i = edges.size() -1;i>=0;i--){
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		adj[u].remove(v);
		adj[v].remove(u);

		if(isConnected() == false){
			adj[u].push_back(v);
			adj[v].push_back(u);

			cout<<"MST edge: "<<u<<" -> "<<v<<endl;
			mstWt += edges[i].first;
		}
	}
	cout<<"TOtal Weight of MST: "<<mstWt<<endl;
}

int main(){
	int V = 9; 
    Graph g(V); 

    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.reverseDeleteMST(); 
    return 0; 
}

//Complexity: O(ElogV)