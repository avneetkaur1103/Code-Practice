//This method uses iterative BFS. We can do using recursive DFS too(use visited arr for color)

#include <iostream>
#include <queue>
using namespace std;

#define V 4

bool BFS(int G[][V], int i, int color[]){
	color[i] = 1;

	queue<int> q;
	q.push(i);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(G[u][u])
			return false;

		for(int v=0;v<V;v++){
			if(G[u][v] && color[v] == -1){
				color[v] = 1 - color[u];
				q.push(v);
			}

			else if(G[u][v] && color[u] == color[v])
				return false;
		}
	}

	return true;
}

bool isBipartite(int G[][V]){
	int color[V];
	for(int i=0;i<V;i++)
		color[i] = -1;

	//for not so strongly connected graph
	for(int i=0;i<V;i++)
		if(color[i] == -1){
			if(BFS(G,i,color) == false)
				return false;
		}

	return true;
}

int main() 
{ 
    int G[][V] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
  
    isBipartite(G) ? cout << "Yes" : cout << "No"; 
    return 0; 
}

//O(V+E) - if using adj list
//O(V^2) - if using adj matrix