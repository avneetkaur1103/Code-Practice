#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph{
public:
	int V;
	list <int> *adj;

	Graph(int V);
	void addEdge(int u, int v);
	vector<int> BFS(int comp,int visited[], int v);
	void printMap(map<int, vector<int> > m, int comp);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::printMap(map<int, vector<int> > m, int comp){
	vector<int> v = m[comp];
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
}


vector<int> Graph::BFS(int comp,int visited[], int v){
	vector<int> con_comp;
	queue<int> q;
	q.push(v);
	visited[v] = comp;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		con_comp.push_back(x);
		list<int>::iterator it;
		for(it = adj[x].begin(); it != adj[x].end(); it++){
			if(!visited[*it]){
				visited[*it] = comp;
				q.push(*it);

			}
		}
	}
	return con_comp;
}

void findReachableNodes(Graph g,int arr[], int n){
	int V = g.V;
	int *visited = new int[V+1];
	for(int i=0;i<V+1;i++)
		visited[i] = 0;

	int comp = 0;
	map<int, vector<int> > m;

	for(int i=0;i<n;i++){
		int x = arr[i];
		if(!visited[x]){
			comp++;
			m[visited[x]] = g.BFS(comp,visited,x);
		}	
		cout<<"Elements reachable from "<<x<<" are ";
		g.printMap(m,visited[x]);
	}

}

int main(){
	int V = 7; 
    Graph g(V); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
    g.addEdge(3, 1); 
    g.addEdge(5, 6); 
    g.addEdge(5, 7); 

    int arr[] = {2, 4, 5}; 
    int n = sizeof(arr)/sizeof(int); 
  
    findReachableNodes(g, arr, n); 
  
    return 0; 
}

//Complexity: O(V+E)