#include <iostream>
#include <list>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	bool isConnected();
	void DFS(int v, bool visited[]);
	int DFSCount(int u, bool visited[]);
	bool isValidMove(int u, int v);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void remEdge(int u, int v);
	void isEulerian();
	void printEulerTour();
	void printEulerUtil(int src);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::remEdge(int u, int v){
	list<int>::iterator it1 = find(adj[u].begin(), adj[u].end(), v);
	*it1 = -1;
	list<int>::iterator it2 = find(adj[v].begin(), adj[v].end(), u);
	*it2 = -1;
}

void Graph::DFS(int v, bool visited[]){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it != adj[v].end(); it++)
		if(!visited[*it])
			DFS(*it,visited);
}

bool Graph::isConnected(){
	bool visited[V];
	int i=0;
	for(i=0;i<V;i++)
		visited[i] = false;

	for(i=0;i<V;i++){
		if(adj[i].size() != 0)
			break;
	}

	if(i == V)
		return true;
	DFS(i,visited);

	for(i=0;i<V;i++){
		if(adj[i].size() > 0 && visited[i] == false)
			return false;
	}

	return true;
}

void Graph::isEulerian(){
	int res=-1;
	if (isConnected() == false)
		res = 0;

	int odd = 0;

	for(int i=0;i<V;i++)
		if(adj[i].size() & 1)
			odd++;

	if(odd > 2)
		res = 0;

	if(odd == 2)
		res = 1;
	else if(odd == 0)
		res = 2;

	if(res == 0)
		cout<<"Not a Eulerian"<<endl;
	else if(res == 1)
		cout<<"This is Eulerian Path"<<endl;
	else if (res == 2)
		cout<<"This is a Eulerian cycle"<<endl;
}

int Graph::DFSCount(int u, bool visited[]){
	visited[u] = true;
	int count = 1;

	list<int>::iterator it;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(!visited[*it] && *it != -1)
			count += DFSCount(*it,visited);
	}

	return count;
}

bool Graph::isValidMove(int u, int v){
	int count =0;
	list<int>::iterator it;

	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(*it != -1)
			count++;
	}

	if(count == 1)
		return true;

	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;

	int c1= DFSCount(u,visited);

	for(int i=0;i<V;i++)
		visited[i] = false;

	remEdge(u,v);

	int c2= DFSCount(u,visited);
	addEdge(u,v);

	if(c1>c2)
		return false;

	return true;
}

void Graph::printEulerUtil(int src){
	list<int>::iterator it;
	for(it = adj[src].begin(); it != adj[src].end(); it++){
		int v = *it;
		if(v != -1 && isValidMove(src,v)){
			cout<<src<<" -- "<<v<<endl;
			remEdge(src,v);
			printEulerUtil(v);
		}
	}
}

void Graph::printEulerTour(){
	int i=0;
	for(i=0;i<V;i++)
		if(adj[i].size() & 1)
			break;

	printEulerUtil(i);
	cout<<endl;
}

int main(){
	Graph g3(5); 
  	g3.addEdge(1, 0); 
  	g3.addEdge(0, 2); 
  	g3.addEdge(2, 1); 
 	g3.addEdge(0, 3); 
 	g3.addEdge(3, 4); 
  	g3.addEdge(3, 2); 
  	g3.addEdge(3, 1); 
  	g3.addEdge(2, 4); 
  	
    g3.isEulerian();
    g3.printEulerTour();

    /*Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.addEdge(4, 0); 
    g2.isEulerian();*/

    return 0;
}

//Complexity: isEulerian() = O(V+E)
//Complexity: Fluery print: O((V+E) * (V+E))