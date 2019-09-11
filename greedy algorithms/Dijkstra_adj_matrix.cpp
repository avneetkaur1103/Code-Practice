#include <iostream>
#include <climits>

using namespace std;
#define V 9

int min_dist(int dist[], bool Sset[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i<V; i++){
		if (Sset[i] == false && dist[i] <= min){
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void printarr(int dist[]){
	for (int i=0;i<V;i++)
		cout<<i << "--    " <<dist[i]<<endl;
}

void Dijkstra(int graph[V][V], int src){
	int dist[V];
	bool Sset[V];
	
	for(int i = 0; i<V; i++){
		dist[i] = INT_MAX;
		Sset[i] = false;
	}
	
	dist[src] = 0;
	for (int count = 0; count <V; count++){
		int u = min_dist(dist, Sset);
		Sset[u] = true;
	
		for (int i=0; i<V; i++){
			if (!Sset[i] && graph[u][i] && dist[u] != INT_MAX && dist[i] > dist[u] + graph[u][i])
				dist[i] = dist[u] + graph[u][i];
		}
	}
	printarr(dist);
}

int main(){
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
	Dijkstra(graph, 0);
	return 0;
}

//Complexity:O(V^2)