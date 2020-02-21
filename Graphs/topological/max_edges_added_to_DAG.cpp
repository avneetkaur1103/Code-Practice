#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
public:
	Graph(int V);
	void addEdge(int u, int v);
	vector<int> topologicalSort();
	void addMaxEdges(vector<int> topo);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v,bool visited[], stack<int> &s){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it!= adj[v].end();it++){
		if(!visited[*it])
			topologicalSortUtil(*it,visited,s);
	}
	s.push(v);
}

vector<int> Graph::topologicalSort(){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	stack<int> s;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,s);
	}

	vector<int> topo;

	while(!s.empty()){
		int t= s.top();
		topo.push_back(t);
		s.pop();
	}
	return topo;
}

void Graph::addMaxEdges(vector<int> topo){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	for(int i=0;i<topo.size();i++){
		int v=topo[i];
		list<int>::iterator it;
		for(it= adj[v].begin();it !=adj[v].end();it++)
			visited[*it] = true;

		for(int j=i+1;j<topo.size();j++){
			if(!visited[topo[j]])
				cout<<v<<" -> "<<topo[j]<<",     ";
			visited[topo[j]] = false;
			
		}
		
	}
}

int main(){
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    vector<int> topo = g.topologicalSort();
    g.addMaxEdges(topo);
    return 0;
}

//Complexity: O(V+E) (DFS)