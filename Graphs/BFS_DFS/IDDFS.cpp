#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool DLS(int src, int target, int maxDepth);

public:
	Graph(int v);
	void addEdge(int u, int v);
	bool IDDFS(int s, int d, int l);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

bool Graph::DLS(int s, int d, int limit){
	if(s == d)
		return true;

	if(limit <=0)
		return false;

	list<int>::iterator it;
	for(it = adj[s].begin();it != adj[s].end(); it++){
		if(DLS(*it,d,limit-1) == true)
			return true;
	}

	return false;
}

bool Graph::IDDFS(int src, int target, int maxDepth){
	for (int i=0;i<= maxDepth; i++){
		if(DLS(src,target,i))
			return true;
	}
	return false;
}

int main(){
	Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(2, 6);

    int target = 6, maxDepth = 3, src = 0; 
    if (g.IDDFS(src, target, maxDepth) == true)
    	cout<<"Reachable";
    else
    	cout<<"Not Reachable";

    return 0;
}	

//Complexity: O(b^d)