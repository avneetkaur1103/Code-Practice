#include <iostream>
#include <vector>

using namespace std;

class Graph
{
	int V;
	vector<int> *adj;
	vector<int> *transpose;

	public:
		Graph(int V);
		void addEdge(vector<int> arr[],int s, int d);
		void insertInGraph();
		void transposeGraph();
		void displayGraph();
};


Graph::Graph(int V){
	this->V = V;
	adj = new vector<int>[V];
	transpose = new vector<int>[V];
}

void Graph::addEdge(vector<int> arr[],int v, int w){
	arr[v].push_back(w);
}

void Graph::transposeGraph(){
	for(int i=0;i<V;i++){
		for(int j=0;j<adj[i].size();j++){
			addEdge(transpose,adj[i][j],i);
		}
	}
}

void Graph::insertInGraph(){
	addEdge(adj,0, 1); 
    addEdge(adj,0, 4); 
    addEdge(adj,0, 3); 
    addEdge(adj,2, 0); 
    addEdge(adj,3, 2); 
    addEdge(adj,4, 1); 
    addEdge(adj,4, 3); 
}

void Graph::displayGraph(){
	for(int i=0;i<V;i++){
		cout<<"["<<i<<"]";
		for(int j=0;j<transpose[i].size();j++)
			cout<<"->"<<transpose[i][j];
		cout<<endl;
	}
}

int main() 
{ 
    Graph g(5);
    g.insertInGraph();
    g.transposeGraph(); 
    g.displayGraph(); 
  
    return 0; 
}

//Complexity: O(V+E)