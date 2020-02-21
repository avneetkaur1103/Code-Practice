#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<pair<int, int> > g[], pair<int, int> Rev[], bool visited[], int u){
	int totalRev = 0;
	visited[u] = true;

	for(int i=0;i<g[u].size();i++){
		int v = g[u][i].first;
		if(!visited[v]){
			Rev[v].first = Rev[u].first +1 ;
			Rev[v].second = Rev[u].second;

			if(g[u][i].second){
				Rev[v].second = Rev[u].second+1;
				totalRev++;
			}
			totalRev += dfs(g,Rev,visited,v);
		}
	}
	return totalRev;
}

void printMinEdgeReverseForRootNode(int edges[][2], int e){
	int v = e+1;
	vector<pair<int, int> > g[v];
	pair<int, int> Rev[v];
	bool visited[v];

	for(int i=0;i<e;i++){
		int u = edges[i][0];
		int v = edges[i][1];

		g[u].push_back(make_pair(v,0));
		g[v].push_back(make_pair(u,1));
	}

	for(int i=0;i<v;i++){
		Rev[i].first = Rev[i].second = 0;
		visited[i] = false;
	}

	int root = 0;

	int totalRev = dfs(g,Rev,visited,root);

	int result =INT_MAX;

	for(int i=0;i<v;i++){
		int r = (totalRev - Rev[i].second) + (Rev[i].first - Rev[i].second);
		if(r < result){
			result = r;
			root = i;
		}
	}
	cout<<"Root: "<<root<<" and reverses: "<<result<<endl;
}

int main() 
{ 
    int edges[][2] = 
    { 
        {0, 1}, 
        {2, 1}, 
        {3, 2}, 
        {3, 4}, 
        {5, 4}, 
        {5, 6}, 
        {7, 6} 
    }; 
    int e = sizeof(edges) / sizeof(edges[0]); 
  
    printMinEdgeReverseForRootNode(edges, e); 
    return 0; 
} 