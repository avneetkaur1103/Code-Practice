#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int printShortestPath(int parent[],int s, int d);
public:
	Graph(int V);
	void addEdge(int u, int v, int weight);
	void findShortestPath(int s,int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[2*V];
}

void Graph::addEdge(int u, int v, int weight){
	if(weight == 2){
		adj[u].push_back(u+V);
		adj[u+V].push_back(v);
	}
	else
		adj[u].push_back(v);
}

int Graph::printShortestPath(int parent[], int s, int d){
	static int level = 0;

	if(parent[s] == -1){
		cout<<"The shortest path between "<<s<<" and "<<d<<" is : "<<s<<" ";
		return level;
	}

	printShortestPath(parent,parent[s],d);

	level++;
	
	if(s<V)
		cout<<s<<" ";

	return level;
}

void Graph::findShortestPath(int s, int d){
	int parent[2*V];
	int visited[2*V];

	for(int i=0;i<2*V;i++){
		parent[i] = -1;
		visited[i] = false;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		if(u == d)
			printShortestPath(parent,u,d);

		list<int>::iterator it;

		for(it = adj[u].begin(); it != adj[u].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
				parent[*it] = u;
			}
		}
	}
}

int main(){
	int V = 4; 
    Graph g(V); 
    g.addEdge(0, 1, 2); 
    g.addEdge(0, 2, 2); 
    g.addEdge(1, 2, 1); 
    g.addEdge(1, 3, 1); 
    g.addEdge(2, 0, 1); 
    g.addEdge(2, 3, 2); 
    g.addEdge(3, 3, 2); 
    int src = 0, dest = 3;
    g.findShortestPath(src, dest);
    return 0;
}

//Complexity:O(V+E)