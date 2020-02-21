#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

#define INF INT_MAX

struct Edge{
	int s, d, w;
};

class Graph{
	int V;
	
	list<pair<int, int> > *adj;
	void removeEdge(int u, int v, int weight);
public:
	vector<Edge> edges;
	Graph(int V);
	void addEdge(int u, int v, int weight);
	int shortestPath(int src, int dest);
	int minWeightCycle();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
	Edge e;
	e.s = u;
	e.d = v;
	e.w = w;
	edges.push_back(e);
}

void Graph::removeEdge(int u, int v, int w){
	adj[u].remove(make_pair(v,w));
	adj[v].remove(make_pair(u,w));
}

int Graph::shortestPath(int s, int d){
	set<pair<int, int> > set;
	vector<int> distance(V,INF);

	set.insert(make_pair(0,s));
	distance[s] = 0;

	while(!set.empty()){
		pair<int,int> p = *(set.begin());
		set.erase(set.begin());

		int u = p.second;

		list< pair<int, int> >::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++){
			int v = (*it).first;
			int w = (*it).second;

			if(distance[v] > distance[u] + w){
				if(distance[v] != INF)
					set.erase(set.find(make_pair(distance[v],v)));

				distance[v] = distance[u]+ w;
				set.insert(make_pair(distance[v],v));
			}
		}

	}
	return distance[d];
}

int min(int x, int y){
	return(x<y?x:y);
}

int Graph::minWeightCycle(){
	int E = edges.size();
	static int minCycleWt = 99999;

	for(int i=0;i<E;i++){
		Edge e = edges[i];
		removeEdge(e.s,e.d,e.w);

		int distance = shortestPath(e.s, e.d);

		minCycleWt = min(minCycleWt, e.w + distance);
		addEdge(e.s,e.d,e.w);
	}
	return minCycleWt;
}

int main() 
{ 
    int V = 9; 
    Graph g(V); 

    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 

    cout<<"Minimum Weight Cycle: "<<g.minWeightCycle(); 
    return 0;
}
//Complexity: O(E * ElogV)
