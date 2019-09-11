#include <iostream>
#include <climits>
#define V 5

using namespace std;

int min_key(int key[], bool isinMST[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i<V; i++){
		if (isinMST[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}

void print_MST(int graph[V][V], int parent[]){
	for (int i=1; i < V; i++)
		cout<<parent[i]<< "--"<< i << "\t: "<<graph[i][parent[i]] << endl;
}

void PrimsMST(int graph[V][V]){
	bool isinMST[V];
	int key[V];
	int parent[V];
	for (int i = 0;i<V; i++){
		key[i] = INT_MAX;
		isinMST[i] = false;
	}
	key[0] = 0 ;
	parent[0] = -1;
	
	for (int count = 0; count<V-1; count++){
		int u = min_key(key,isinMST);
		isinMST[u] = true;
		
		for (int v= 0; v<V; v++){
			if (graph[u][v] && isinMST[v] == false && graph[u][v] < key[v]){
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	
	print_MST(graph,parent);
}

int main() {
	
	int graph[V][V] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}};
  
  PrimsMST(graph);
	return 0;
}


//Complexity: O(v^2)