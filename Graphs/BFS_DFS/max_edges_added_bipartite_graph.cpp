#include <iostream>
#include <vector>
using namespace std;

int color[2];

void dfs(vector<int> adj[], int node, int parent, int clr){
	color[clr]++;

	for(int i=0;i<adj[node].size(); i++){
		if(adj[node][i] != parent)
			dfs(adj,adj[node][i], node, !clr);
	}
}

int findMaxEdges(vector<int> adj[], int n){

	dfs(adj,1,0,0);
	return (color[0] * color[1] - (n-1));
}

int main() 
{ 
    int n = 5; 
    vector<int> adj[n + 1]; 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(4); 
    adj[3].push_back(5); 
    cout << findMaxEdges(adj, n); 
    return 0; 
} 

//Complexity: O(n)