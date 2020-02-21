#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

class Graph{
	int V;
	list<pair<int, int> > *adj;
public:
	Graph(int V);
	void addEdge(int u,int v,int w);
	vector<int> shortestPath(int src);
	int getMinEdgeReversal(int edge[][2], int E,int V,int src, int dest);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w){
	adj[u].push_back(make_pair(v,w));
	//adj[v].push_back(make_pair(u,w));
}

Graph modelGraph(int edge[][2], int E, int V){
	Graph g(V);
	for(int i=0;i<E;i++){
		int u = edge[i][0];
		int v = edge[i][1];

		g.addEdge(u,v,0);
		g.addEdge(v,u,1);
	}
	return g;
}

vector<int> Graph::shortestPath(int src){
	set<pair<int, int> >s;
	vector<int> distance(V, INT_MAX);
	s.insert(make_pair(0,src));
	distance[src] = 0;

	while(!s.empty()){
		pair<int, int> p = *(s.begin());
		s.erase(s.begin());

		int u = p.second;
		list<pair<int , int> >::iterator it;
		for(it = adj[u].begin();it != adj[u].end();it++){
			int v = (*it).first;
			int w = (*it).second;

			if(distance[v] > distance[u] + w){
				if(distance[v] != INT_MAX)
					s.erase(s.find(make_pair(distance[v],v)));

				distance[v] = distance[u] + w;
				s.insert(make_pair(distance[v],v));
			}
		}
	}
	return distance;
}

int getMinEdgeReversal(int edge[][2], int E, int V, int src, int dest){
	Graph g = modelGraph(edge,E,V);

	vector<int> distance = g.shortestPath(src);

	if(distance[dest] == INT_MAX)
		return -1;
	else
		return distance[dest];

}

int main(){
	int V = 7; 
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, 
                     {4, 5}, {6, 4}, {6, 3}}; 
    int E = sizeof(edge) / sizeof(edge[0]); 
  
    int minEdgeToReverse = 
                  getMinEdgeReversal(edge, E, V, 0, 6); 
    if (minEdgeToReverse != -1) 
        cout << minEdgeToReverse << endl; 
    else
        cout << "Not possible" << endl; 
    return 0;
}