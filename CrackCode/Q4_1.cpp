#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void bfs(queue<int> q, int parent[], bool visited[]);
	int intersection_point(bool v1[], bool v2[]);
	public:
		Graph(int V);
		void addEdge(int u, int v);
		bool biDirectionalSearch(int s, int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::bfs(queue<int> q, int parent[], bool visited[]){
	

	while(!q.empty()){
		int temp = q.front();
		q.pop();

		for(list<int>::iterator it = adj[temp].begin();it != adj[temp].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
				parent[*it] = temp;
			}
		}
	}
}

int Graph::intersection_point(bool v1[], bool v2[]){
	for(int i=0;i<V;i++){
		if(v1[i] && v2[i])
			return i;
	}
	return -1;
}

bool Graph::biDirectionalSearch(int s, int d){
	queue<int> q1,q2;
	int intrsc_pt=-1;

	bool v1[V],v2[V];
	for(int i=0;i<V;i++){
		v1[i] = false;
		v2[i] = false;
	}

	int p1[V],p2[V];

	v1[s] = true;
	v2[d] = true;

	q1.push(s);
	q2.push(d);

	p1[s]=-1;
	p2[d]=-1;

	bfs(q1,p1,v1);
	bfs(q2,p2,v2);
	intrsc_pt = intersection_point(v1,v2);

	if(intrsc_pt == -1)
		return false;
	else
		return true;
}

int main(){
	int v=15;
	int s=0, t=14;
	Graph g(v);
	g.addEdge(0,4);
	g.addEdge(1, 4); 
	g.addEdge(2, 5); 
	g.addEdge(3, 5); 
	g.addEdge(4, 6); 
	g.addEdge(5, 6); 
	g.addEdge(6, 7); 
	g.addEdge(7, 8); 
	g.addEdge(8, 9); 
	g.addEdge(8, 10); 
	g.addEdge(9, 11); 
	g.addEdge(9, 12); 
	g.addEdge(10, 13); 
	g.addEdge(10, 14);

	g.biDirectionalSearch(s,t)?cout<<"Path exists":cout<<"Path does not exists";
	return 0;
}
