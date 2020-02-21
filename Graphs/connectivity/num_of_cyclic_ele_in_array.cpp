#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	int DFS(int v, bool visited[]);
	void fillStack(int v, bool visited[],stack<int> &s);
	Graph transposeGraph();
public:
	Graph(int V);
	void addEdge(int u, int v);
	int getCountSCC();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	cout<<u<<"-->"<<v<<endl;
}

void Graph::fillStack(int v, bool visited[],stack<int> &s){
	visited[v] = true;
	list<int>::iterator it;
	for(it = adj[v].begin();it != adj[v].end(); it++){
		if(!visited[*it])
			fillStack(*it,visited,s);
	}
	s.push(v);
}

int Graph::DFS(int v,bool visited[]){
	int count = 1;
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin();it != adj[v].end(); it++){
		if(!visited[*it])
			count += DFS(*it,visited);
	}
	return count;
}

Graph Graph::transposeGraph(){
	Graph g(V);
	for(int i=0;i<V;i++){
		list<int>::iterator it;
		for(it = adj[i].begin(); it != adj[i].end(); it++){
			g.addEdge(*it,i);
		}
	}
	return g;
}

int Graph::getCountSCC(){
	int count = 0;
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	stack<int> s;

	for(int i=0;i<V;i++)
		if(!visited[i])
			fillStack(i,visited,s);

	Graph gT = transposeGraph();

	for(int i=0;i<V;i++)
		visited[i] = false;

	while(!s.empty()){
		int k = s.top();
		s.pop();
		
		if(!visited[k]){
			int c = gT.DFS(k,visited);
			if(c>1)
				count += c;
		}
	}
	return count;
	
}

int countCyclic(int arr[], int n){
	Graph g(n+1);
	int count = 0;
	for(int i=0;i<n;i++){
		int v = (i+arr[i])%n + 1;
		if(v == i)
			count++;
	
		g.addEdge(i,v);
	}
	count += g.getCountSCC();
	return count;
}

int main(){
    int arr[] = {1, 1, 1, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << countCyclic(arr, n); 
    return 0; 
}

//Complexity: O(n)