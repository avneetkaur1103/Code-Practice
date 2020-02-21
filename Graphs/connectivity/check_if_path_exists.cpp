#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list <int> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isReachable(int s, int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

bool Graph::isReachable(int s, int d){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	//BFS
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		list<int>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++){
			if (!visited[*it]){
				if(*it == d)
					return true;
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	return false;
}

int main(){
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    int u = 1, v = 3; 
    if(g.isReachable(u, v))
    	cout<<"Path Exists";
    else
    	cout<<"Path does not exists";

    cout<<endl;

    u = 3, v = 1; 
    if(g.isReachable(u, v))
    	cout<<"Path Exists";
    else
    	cout<<"Path does not exists";
    return 0;
}