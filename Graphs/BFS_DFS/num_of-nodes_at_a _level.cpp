#include <iostream>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int v, int w);
		int BFS(int s, int l);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

int Graph::BFS(int u, int l){
	bool *visited = new bool[V];
	int level[V];

	for(int i=0;i<V;i++){
		visited[i] = false;
		level[i] = 0;
	}


	list<int> q;
	visited[u] = true;
	level[u] = 0;
	q.push_back(u);

	while(!q.empty()){
		int temp = q.front();
		//cout<<temp<<" ";
		q.pop_front();

		list<int>::iterator it;
		for(it = adj[temp].begin(); it != adj[temp].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				level[*it] = level[temp] + 1;
				q.push_back(*it);
			}
		}
	}

	int count = 0;

	for(int i=0;i<V;i++){
		if(level[i] == l)
			count++;
	}
	return count;
}

int main(){
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,5);
	int level = 2;
	cout<<g.BFS(0,level);
	return 0;
}

//Complexity: O(V+E)