#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool DFSUtil(vector<bool> &visited, vector<int> &vDegree, int startVt, int k );

	public:
		Graph(int V);
		void addEdge(int v, int w);
		void printKCores(int k);
};


Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::DFSUtil(vector<bool> &visited, vector<int> &vDegree, int startV, int k){
	visited[startV] = true;
	
	list<int>::iterator it;

	for(it = adj[startV].begin(); it != adj[startV].end(); it++){
		if(vDegree[startV]<k)
			vDegree[*it]--;

		if(!visited[*it])
			if(DFSUtil(visited, vDegree, *it, k))
				vDegree[startV]--;
	}
	return(vDegree[startV] < k);
}

void Graph::printKCores(int k){
	vector<bool> visited(V,false);

	int minDegree = INT_MAX;
	int startV;
	vector<int> vDegree(V);

	for(int i = 0; i<V;i++){
		vDegree[i] = adj[i].size();
		if(vDegree[i] < minDegree){
			startV = i;
			minDegree = vDegree[i];
		}
	}

	for(int i = 0;i<V;i++){
		if(!visited[i])
			DFSUtil(visited,vDegree,startV,k);
	}

	for(int i=0;i<V;i++){
		if(vDegree[i] >= k){
			cout<<endl;
			cout<<"["<<i<<"]";
		

			list<int>::iterator it;

			for(it = adj[i].begin(); it != adj[i].end(); it++){
				if(vDegree[*it] >= k)
					cout<<"->"<<*it;
			}
		}
	}
}

int main(){
	int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8);

    g1.printKCores(k); 
  
	return 0;
}

//Complexity: O(V+E)