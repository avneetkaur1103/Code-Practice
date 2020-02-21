#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool **tc;
	void DFSUtil(int u, int v);
	public:
		Graph(int v);
		void addEdge(int u, int v);
		void transitiveClosure();
};

Graph::Graph(int v){
	this->V = v;
	adj = new list<int>[v];
	tc = new bool*[V];
	for(int i=0;i<V;i++){
		tc[i] = new bool[v];
		memset(tc[i], false, V*sizeof(bool));
	}
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::DFSUtil(int u, int v){
	tc[u][v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(tc[u][*it] == false){
			DFSUtil(u,*it);
		}
	}
}

void Graph::transitiveClosure(){
	for(int i=0;i<V;i++)
		DFSUtil(i,i);

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
			cout<<tc[i][j]<<" ";
		cout<<endl;
	}

}

int main(){
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    g.transitiveClosure();
    return 0;
}

//Complexity: O(V^2)