#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
	int getIndex(int i, vector<int> topo);

public:
	Graph(int V);
	void addEdge(int u, int v);
	int countEdges();
	stack<int> topologicalSort();
	void addDir(vector<int> topo,vector<int> undirEdges[]);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}


int Graph::countEdges(){
	int sum =0;
	for(int i=0;i<V;i++){
		sum += adj[i].size();
	}
	return sum;
}

void Graph::topologicalSortUtil(int v,bool visited[], stack<int> &s){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it!= adj[v].end();it++){
		if(!visited[*it])
			topologicalSortUtil(*it,visited,s);
	}
	s.push(v);
}

stack<int> Graph::topologicalSort(){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	stack<int> s;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,s);
	}

	return s;
}

int Graph::getIndex(int i, vector<int> topo){
	for(int k=0;k<topo.size();k++){
		if(topo[k] == i)
			return k;
	}
	return -1;
}

void Graph::addDir(vector<int> topo,vector<int> undirEdges[]){
	for(int i=0;i<V;i++){
		for(int j=0;j<undirEdges[i].size();j++){
				if(undirEdges[i][j] && getIndex(i,topo) < getIndex(undirEdges[i][j],topo)){
					//cout<<i<<" -> ";
					//cout<<undirEdges[i][j]<<" ";
					addEdge(i,undirEdges[i][j]);
				}
		}
		//cout<<endl;
	}
}

int main(){
	Graph g(6); 
    g.addEdge(0,1); 
    g.addEdge(1,2); 
    g.addEdge(0,5); 
    g.addEdge(1,3); 
    g.addEdge(1,4); 
    g.addEdge(5,1);
    g.addEdge(5,2);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
   
    stack<int> topo = g.topologicalSort();
    vector<int> t;
    while(!topo.empty()){
		cout<<topo.top()<<" ";
		t.push_back(topo.top());
		topo.pop();
	}
    cout<<endl;
    cout<<"Number of edges before adding undir edges: "<<g.countEdges()<<endl;

	vector<int> *undirEdges = new vector<int>[6];
	undirEdges[0].push_back(2);
	undirEdges[2].push_back(0);
	undirEdges[0].push_back(3);
	undirEdges[3].push_back(0);
	undirEdges[4].push_back(5);
	undirEdges[5].push_back(4);

    g.addDir(t,undirEdges);

    cout<<"Number of edges after adding undir edges: "<<g.countEdges()<<endl;

   	topo = g.topologicalSort();
   	while(!topo.empty()){
		cout<<topo.top()<<" ";
		topo.pop();
	}
    cout<<endl;

    return 0;
}

//Complexity: O(V+E) (DFS)