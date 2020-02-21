#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void DFS(int s);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFS(int u){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	stack<int> s;
	
	s.push(u);

	while (!s.empty()){
		int temp = s.top();
		
		s.pop();

		if(!visited[temp]){
			cout<<temp<<" ";
			visited[temp] = true;
		}

		list<int>::iterator it;
		for(it = adj[temp].begin(); it != adj[temp].end(); it++){
			if(!visited[*it]){
				s.push(*it);
			}
		}
	}
	
}

int main(){
	Graph g(5);
	g.addEdge(1,0);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(0,3);
	g.addEdge(1,4);
	
	g.DFS(0);
	return 0;
}

//Complexity: O(V+E)