#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void  APUtil(int i, bool visited[], int parent[], int disc[], int low[], bool ap[]);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void AP();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::APUtil(int i, bool visited[], int parent[], int disc[], int low[], bool ap[]){
	visited[i] = true;
	static int time =0;
	disc[i] = low[i] = ++time;
	int children = 0;
	list<int>::iterator it;
	for(it = adj[i].begin();it != adj[i].end(); it++){
		int v = *it;

		if(!visited[v]){
			children++;
			parent[v] = i;
			APUtil(v,visited,parent,disc,low,ap);

			low[i] = min(low[i],low[v]);

			if(parent[i] == -1 && children > 1)
				ap[i] = true;

			if(parent[i] != -1 && low[v] >= disc[i])
				ap[i] = true;
		}
		else if(v != parent[i]){
			low[i] = min(low[i],disc[v]);
		}
	}

}

void Graph::AP(){
	bool *visited = new bool[V];
	int *parent = new int[V];
	int *disc = new int[V];
	int *low = new int[V];
	bool *ap = new bool[V];

	for(int i=0;i<V;i++){
		visited[i] = false;
		ap[i] = false;
		parent[i] = -1;
	}

	for(int i=0;i<V;i++){
		if(!visited[i])
			APUtil(i,visited,parent,disc,low,ap);
	}

	for(int i=0;i<V;i++){
		if(ap[i])
			cout<<i<<" ";
	}
}

int main(){
	Graph g1(5);
	g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.AP();
    return 0;
}

//Complexity: O(V+E)