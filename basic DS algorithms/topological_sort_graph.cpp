#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *edges;
	void topoUtility(int v, bool visited[], stack<int> &stack);
	public:
		Graph(int v);
		void addEdge(int u, int v);
		void TopologicalSort();
};

Graph::Graph(int v){
	this->V = v;
	edges = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	edges[u].push_back(v);
}

void Graph::topoUtility(int v, bool visited[], stack<int> &stack){
	visited[v] = true;
	list<int>::iterator it;
	for(it = edges[v].begin();it != edges[v].end();++it){
		if(!visited[*it])
			topoUtility(*it,visited,stack);
	}
		stack.push(v);
	
}

void Graph::TopologicalSort(){
	bool *visited = new bool[V];
	for (int i = 0;i<V;i++){
		visited[i] = false;
	}
	stack<int> stack;
	for (int j = 0;j<V;j++){
		if (visited[j] == false)
			topoUtility(j,visited,stack);
	}
	
	while (!stack.empty()){
		cout << stack.top() << "\t";
		stack.pop();
	}
}
int main() {
	Graph g(6);
	g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1);
    g.TopologicalSort();
	return 0;
}