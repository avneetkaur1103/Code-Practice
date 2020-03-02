#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(stack<int> &s, bool visited[], int node);

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

void Graph::topologicalSortUtil(stack<int> &s, bool visited[], int node){
	visited[node] = true;
	list<int>::iterator it;
	for(it = adj[node].begin(); it!= adj[node].end(); it++){
		if(!visited[*it])
			topologicalSortUtil(s,visited,*it);
	}

	s.push(node);
}

void Graph::topologicalSort(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	stack<int> s;

	for(int i=0;i<V;i++){
		if(!visited[i]){
			topologicalSortUtil(s,visited,i);
		}
	}

	if(s.empty()){
		cout<<"No valid build order"<<endl;
		return;
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
