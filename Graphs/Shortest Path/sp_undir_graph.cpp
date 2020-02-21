#include <iostream>
#include <vector>
#include <queue>
using  namespace std;

void add_edge(vector<int> adj[],int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool BFS(vector<int> adj[],int s, int d, int v, int parent[], int distance[]){
	bool visited[v];

	for(int i=0;i<v;i++)
		visited[i] = false;

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		vector<int>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				distance[*it] = distance[u] + 1;
				parent[*it] = u;
				q.push(*it);

				if(*it == d)
					return true;
			}
		}
	}
	return false;
}

void printShortestDistance(vector<int> adj[],int s, int d, int v){
	int parent[v];
	int distance[v];
	for(int i=0;i<v;i++){
		parent[i] = -1;
		distance[i] = 0;
	}

	if(BFS(adj,s,d,v,parent,distance) == false){
		cout<<"No path"<<endl;
		return;
	}

	int x = d;
	vector<int> path;
	path.push_back(x);
	while(parent[x] != -1){
		path.push_back(parent[x]);
		x = parent[x];
	}

	cout<<"Shortest path length: "<< distance[d]<<endl;
	cout<<"Shortest Path: ";
	for(int i=path.size() - 1; i>=0; i--){
		cout<<path[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int v = 8;
	vector<int> adj[v];
	add_edge(adj, 0, 1); 
    add_edge(adj, 0, 3); 
    add_edge(adj, 1, 2); 
    add_edge(adj, 3, 4); 
    add_edge(adj, 3, 7); 
    add_edge(adj, 4, 5); 
    add_edge(adj, 4, 6); 
    add_edge(adj, 4, 7); 
    add_edge(adj, 5, 6); 
    add_edge(adj, 6, 7); 
    int source = 0, dest = 7; 
    printShortestDistance(adj, source, dest, v); 
    return 0; 
}
//Time Complexity: O(V+E)
//Space Complexity: O(V)