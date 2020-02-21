#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(bool visited[], int v);
	public:
		Graph(int v);
		void addEdge(int u, int v);
		int findMother();
};

Graph::Graph(int v){
	this->V = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::DFSUtil(bool visited[], int v){
	visited[v] = true;
	//cout<<v<<" ";

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++){
		if(!visited[*it]){
			DFSUtil(visited,*it);
		}
	}
}

int Graph::findMother(){

	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	int vMother= 0;

	for(int i=0;i<V;i++){
		if(!visited[i]){
			DFSUtil(visited,i);
		
			vMother = i;
		}
	}

	

	for(int i=0;i<V;i++)
		visited[i] = false;

	DFSUtil(visited,vMother);

	for(int i=0;i<V;i++)
		if(visited[i] == false)
			return -1;
		else
			return vMother;
}

int main(){
	Graph g(7);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0);
    cout<<g.findMother();
    return 0;
}

//Complexity: O(V+E)

//Brute Force Method: O(V(V+E)) -- not recommended