#include <iostream>
#include <list>
#include <vector>
#include <queue>
#define N 4

using namespace std;

class Graph{
	int V;
	list<int> *adj;

public:
	Graph(int v);
	void addEdge(int u, int v);
	int bfs(int s, int d);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isSafe(int x, int y, int M[][N]){
	if(x<0 || x>=N ||y<0 || y>=N || M[x][y] == 0)
		return false;

	return true;
}

int Graph::bfs(int s, int d){
	if(s == d)
		return 0;
	int *distance = new int[V];

	for(int i=0;i<V;i++)
		distance[i] = -1;

	queue<int> q;
	q.push(s);
	distance[s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		list<int>::iterator it;
		for(it=adj[u].begin();it != adj[u].end();it++){
			if(distance[*it] < 0 || distance[*it] > distance[u] +1){
				distance[*it] = distance[u]+1;
				q.push(*it);
			}

		}
	}
	return distance[d];


}

int MinimumPath(int M[N][N]){
	int s, d;
	int V= N*N+2;
	Graph g(V);

	int k=1;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(M[i][j] != 0){
				if(isSafe(i,j+1,M))
					g.addEdge(k,k+1);

				if(isSafe(i,j-1,M))
					g.addEdge(k,k-1);

				if(j<N-1 && isSafe(i+1,j,M))
					g.addEdge(k,k+N);

				if(j>0 && isSafe(i-1,j,M))
					g.addEdge(k,k-N);
			}

			if(M[i][j] == 1)
				s = k;

			if(M[i][j] == 2)
				d = k;
			k++;
		}

	}

	return g.bfs(s,d);
}

int main(){
	int M[N][N] = {{ 3 , 3 , 1 , 0 }, 
        { 3 , 0 , 3 , 3 }, 
        { 2 , 3 , 0 , 3 }, 
        { 0 , 3 , 3 , 3 } 
    }; 
  
    cout << MinimumPath(M) << endl; 
  
    return 0; 
}