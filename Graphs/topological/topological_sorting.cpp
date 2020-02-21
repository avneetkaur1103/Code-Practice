#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void topologicalSort();
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

void Graph::topologicalSort(){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	stack<int> s;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,s);
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
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

    g.topologicalSort();
    return 0;
}

//Complexity: O(V+E) (DFS)