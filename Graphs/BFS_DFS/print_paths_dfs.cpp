#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void printPathsUtil(int s, int d, bool vis[], int path[], int p_idx);

public:
	Graph(int V);
	void addEdge(int u, int v);
	void printPaths(int s, int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::printPaths(int s, int d){
	bool vis[V];
	for(int i=0;i<V;i++)
		vis[i] = false;

	int *path = new int[V];
	int p_idx =0;

	printPathsUtil(s,d,vis,path,p_idx);

}

void Graph::printPathsUtil(int s, int d, bool vis[], int path[], int p_idx){
	vis[s]= true;
	path[p_idx] = s;
	p_idx++;

	if(s==d){
		for(int i=0;i<p_idx;i++)
			cout<<path[i]<<" ";
		cout<<endl;
	}
	else{
		list<int>::iterator it;
		for(it = adj[s].begin(); it != adj[s].end(); it++){
			if(!vis[*it])
				printPathsUtil(*it,d,vis,path,p_idx);
		}
	}
	p_idx--;
	vis[s] = false;
}

int main(){
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
  
    int s = 2, d = 3;
    g.printPaths(s, d);
    return 0;
}

//Complexity: O(V+E)