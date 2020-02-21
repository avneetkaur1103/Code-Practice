#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<pair<int,int> >  *adj;
	bool pathMoreThanKUtil(int src, int k, vector<bool> &path);

public:
	Graph(int V);
	void addEdge(int u, int v,int w);
	bool pathMoreThanK(int src, int k);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<pair<int, int> >[V];
}

void Graph::addEdge(int u,int v,int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path){
	if(k<=0)
		return false;
	list< pair<int,int> >::iterator it;
	for(it = adj[src].begin(); it != adj[src].end(); it++){
		int v = (*it).first;
		int w = (*it).second;

		if(path[v] == true)
			continue;

		if(w >=k)
			return true;

		path[v] = true;
		if(pathMoreThanKUtil(v,k-w,path) == true)
			return true;

		path[v] = false;
	}
	return false;
}

bool Graph::pathMoreThanK(int src, int k){
	vector<bool> path(V,false);
	path[src] = true;
	return pathMoreThanKUtil(src,k,path);
}

int main(){
	int V=9;
	Graph g(V);

	g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    int src = 0; 
    int k = 62; 

    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n";

    k = 60; 
    g.pathMoreThanK(src, k)? cout << "Yes\n" : 
                             cout << "No\n"; 
  
    return 0;
}

//Complexity: O(n!)