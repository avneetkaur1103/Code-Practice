#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], int total_sum, int subtree[], int &res){
	int sum = subtree[node];

	for(int i=0;i<adj[node].size();i++){
		int v = adj[node][i];
		if(v != parent){
			dfs(v,node,adj,total_sum,subtree,res);
			sum += subtree[v];
		}
	}

	subtree[node] = sum;

	if(node !=0 && abs(total_sum - 2*sum) <res)
		res = abs(total_sum - 2*sum);
}

int getMinSubtreeSumDifference(int vertex[], int edges[][2], int N){
	vector<int> adj[N];
	for(int i=0;i<N-1;i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int total_sum = 0;
	int subtree[N];

	for (int i=0;i<N;i++){
		subtree[i] = vertex[i];
		total_sum += vertex[i];
	}

	int res = INT_MAX;

	dfs(0,-1,adj,total_sum,subtree,res);
	return res;
}

int main(){
	int vertex[] = {4, 2, 1, 6, 3, 5, 2}; 
    int edges[][2] = {{0, 1}, {0, 2}, {0, 3}, 
                      {2, 4}, {2, 5}, {3, 6}}; 
    int N = sizeof(vertex) / sizeof(vertex[0]); 
  
    cout << getMinSubtreeSumDifference(vertex, edges, N); 
    return 0; 
}