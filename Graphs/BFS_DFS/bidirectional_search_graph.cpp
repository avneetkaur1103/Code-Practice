#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void printPath(int *s_parent,int *t_parent,int s,int t,int intrsec);
	public:
		Graph(int V);
		void addEdge(int u, int v);
		int isIntersection(bool s_vis[], bool t_vis[]);
		void biDirSearch(int s, int t);
		void bfs(bool *visited, int *parent, queue<int> *q);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	this->adj[u].push_back(v);
	this->adj[v].push_back(u);
}

void Graph::bfs(bool *visited, int *parent, queue<int> *q){
	int u = q->front();
	q->pop();

	list<int>::iterator it;

	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(!visited[*it]){
			parent[*it] = u;
			visited[*it] = true;
			q->push(*it);
		}
	}
}

int Graph::isIntersection(bool s_vis[], bool t_vis[]){
	for(int i=0;i<V;i++){
		if(s_vis[i] && t_vis[i]){
			//cout<<"intersec point: "<<i<<endl;
			return i;
		}
	}
		return -1;
}

void Graph::printPath(int *s_parent,int *t_parent,int s,int t,int intrsec){
	vector<int> path;
	path.push_back(intrsec);
	int item = intrsec;

	while(item != s){
		path.push_back(s_parent[item]);
		item = s_parent[item];
	}

	reverse(path.begin(), path.end());

	item = intrsec;
	while(item != t){
		path.push_back(t_parent[item]);
		item = t_parent[item];
	}

	vector<int>::iterator it;
	for(it = path.begin(); it != path.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void Graph::biDirSearch(int s, int t){
	bool s_vis[V], t_vis[V];
	int s_parent[V], t_parent[V];
	queue<int> s_q, t_q;
	int intrsec = -1;

	for(int i=0;i<V;i++){
		s_vis[i] = false;
		t_vis[i] = false;		
	}

	s_q.push(s);
	s_vis[s] = true;
	s_parent[s] = -1;
	
	t_q.push(t);
	t_vis[t] = true;
	t_parent[t] = -1;
	

	while(!s_q.empty() && !t_q.empty()){
		bfs(s_vis,s_parent,&s_q);
		bfs(t_vis,t_parent,&t_q);


		intrsec = isIntersection(s_vis,t_vis);

		if(intrsec != -1){
			cout<<"Intersecting at : "<<intrsec<<endl;
			printPath(s_parent,t_parent,s,t,intrsec);
			return;
		}
		
	}

	if(intrsec == -1)
		cout<<"No intersection found"<<endl;

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

	g.biDirSearch(s,t);
	return 0;
}

//Time & Space Complexity: O(b^ d/2) - where b - branching factor and d is dist between source and destination.