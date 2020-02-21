#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void bridgeUtil(int i, int disc[], int low[], bool visited[], int parent[]);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void bridge();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::bridgeUtil(int i, int disc[], int low[], bool visited[], int parent[]){
	
	static int time =0;
	disc[i] = low[i] = ++time;
	visited[i] = true;
	
	list<int>::iterator it;
	for(it = adj[i].begin();it != adj[i].end(); it++){
		int v = *it;

		if(!visited[v]){
			parent[v] = i;
			bridgeUtil(v,disc,low,visited,parent);

			low[i] = min(low[i],low[v]);

			if(low[v] > disc[i])
				cout<<i<<" "<<v<<endl;
		}
		else if(parent[i] != v){
			low[i] = min(low[i],disc[v]);
		}
	}
}

void Graph::bridge(){
	int *disc = new int[V];
	int *low = new int[V];
	bool *visited = new bool[V];
	int *parent = new int[V];

	for(int i=0;i<V;i++){
		parent[i] = -1;
		visited[i] = false;
		disc[i] = -1;
		low[i] = -1;
	}

	for(int i=0;i<V;i++){
		if(!visited[i])
			bridgeUtil(i,disc,low,visited,parent);
	}
}

int main(){
	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.bridge(); 
    return 0;
}

//Complexity: O(V+E)