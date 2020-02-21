#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list <int> *adj;
	void DFS(int v, bool visited[]);
	void pushInStack(int v, bool visited[], stack<int> *s);
	Graph transposeGraph();
public:
	Graph(int V);
	void addEdge(int u, int v);
	void printSSC();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::DFS(int s, bool visited[]){
	visited[s] = true;
	cout<<s<<" ";
	list<int>::iterator it;
	for(it = adj[s].begin();it != adj[s].end(); it++){
		if(!visited[*it])
			DFS(*it,visited);
	}
}

void Graph::pushInStack(int v, bool visited[], stack<int> *s){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin();it != adj[v].end(); it++){
		if(!visited[*it])
			pushInStack(*it,visited,s);
	}
	s->push(v);
}

Graph Graph::transposeGraph(){
	Graph g(V);
	for(int i=0;i<V;i++){
		list<int>::iterator it;
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			g.addEdge(*it,i);
		}
	}
	return g;
}

void Graph::printSSC(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	stack<int> *s = new stack<int>();

	for(int i=0;i<V;i++){
		if(!visited[i])
			pushInStack(i,visited,s);
	}
	
	Graph g1 = transposeGraph();
	for(int i=0;i<V;i++)
		visited[i] = false;


	while(!s->empty()){
		int v = s->top();
		s->pop();
		if(!visited[v]){
			g1.DFS(v,visited);
			cout<<endl;
		}

	}
}

int main(){
	Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  	g.printSSC();
    return 0;
}

//Complexity: O(V+E)