#include <iostream>
#include <queue>

using namespace std;

#define V 6

bool BFS(int rGraph[][V], int s, int d, int parent[]){
	bool visited[V];

	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v = 0;v<V;v++){
			if(!visited[v] && rGraph[u][v] > 1){
				q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
		}
	}
	return(visited[d] == true);
}

void dfs(int rGraph[][V], bool visited[], int s){
	visited[s] = true;
	for(int i=0;i<V;i++){
		if(rGraph[s][i] && !visited[i])
			dfs(rGraph,visited,i);
	}
}

void minCut(int Graph[][V], int s, int d){
	int rGraph[V][V];
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++)
			rGraph[i][j] = Graph[i][j];
	}

	int max_flow = 0;
	int parent[V];
	//bool visited[V];

	for(int i=0;i<V;i++){
		parent[i] = -1;
		//visited[i] = false;
	}

	int u,v;
	

	while(BFS(rGraph,s,d,parent)){
		int minFlow = INT_MAX;
		for(int v=d;v!=s;v = parent[v]){
			u = parent[v];
			minFlow = min(minFlow,rGraph[u][v]);
		}

		for(int v=d;v!=s;v = parent[v]){
			u = parent[v];
			rGraph[u][v] -= minFlow;
			rGraph[v][u] += minFlow;
		}
		//max_flow += minFlow;
	}

	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	for(int i=0;i<V;i++)
		dfs(rGraph,visited,s);

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(!visited[j] && visited[i] && Graph[i][j])
				cout<<i<<" --> "<<j<<endl;
		}
	}
	//return max_flow;
}

int main(){
	int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      };  
  
    minCut(graph, 0, 5); 
  
    return 0; 
}

//Complexity: O(E* V^3)
//min s-t capacity = max floa