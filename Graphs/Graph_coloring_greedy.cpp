#include <iostream>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	void greedyColoring();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::greedyColoring(){
	int result[V];
	result[0] = 0;
	for(int i=1;i<V;i++)
		result[i] = -1;

	bool clrAvailability[V];
	for(int i=0;i<V;i++)
		clrAvailability[i] = true;

	for(int i=1;i<V;i++){
		list<int>::iterator it;
		for(it = adj[i].begin(); it != adj[i].end(); it++)
			if(result[*it] != -1)
				clrAvailability[result[*it]] = false;
		int j;

		for(j=0;j<V;j++)
			if(clrAvailability[j] == true)
				break;

		result[i] = j;

		for(it = adj[i].begin(); it != adj[i].end(); it++)
			if(result[*it] != -1)
				clrAvailability[result[*it]] = true;
	}

	for(int i=0;i<V;i++)
		cout<<i<<"-->"<<result[i]<<endl;
}

int main(){
	Graph g1(5); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 3); 
    g1.addEdge(2, 3); 
    g1.addEdge(3, 4); 
    g1.greedyColoring();
    return 0;
}