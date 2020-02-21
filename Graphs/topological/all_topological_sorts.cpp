#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	vector<int> indeg;
	void alltopologicalSortUtil(bool visited[], vector<int> &res);
public:
	Graph(int V);
	void addEdge(int u,int v);
	void alltopologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	for(int i=0;i<V;i++)
		indeg.push_back(0);
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	indeg[v]++;
}

void Graph::alltopologicalSortUtil(bool visited[], vector<int> &res){
	bool flag = false;

	for(int i=0;i<V;i++){
		if(!visited[i] && indeg[i] == 0){
			list<int>::iterator it;
			for(it= adj[i].begin();it != adj[i].end(); it++)
				indeg[*it]--;
			res.push_back(i);
			visited[i] = true;
			alltopologicalSortUtil(visited,res);

			visited[i] = false;
			res.erase(res.end() - 1);
			
			for(it= adj[i].begin();it != adj[i].end(); it++)
				indeg[*it]--;

			flag = true;
			
		}
	}

	if(!flag){
		for(int i=0;i<V;i++){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}

void Graph::alltopologicalSort(){
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	vector<int> res;
	alltopologicalSortUtil(visited,res);
}

int main() 
{
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "All Topological sorts\n"; 
  
    g.alltopologicalSort(); 
  
    return 0; 
} 