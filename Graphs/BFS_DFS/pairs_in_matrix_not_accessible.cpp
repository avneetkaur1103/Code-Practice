#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> graph[], bool vis[],int *k, int i){
	for(int j=0;j<graph[i].size();j++){
		if(!vis[graph[i][j]]){
			(*k)++;
			vis[graph[i][j]] = true;
			dfs(graph,vis,k,graph[i][j]);
		}
	}
}

int countNonAccessible(vector<int> graph[], int N){
	int v = N*N + 1;
	bool vis[v];
	for(int i=0;i<v;i++)
		vis[i] = false;

	int ans = 0;

	for(int i=1;i<v;i++){
		if(!vis[i]){
			vis[i] = true;
			int k=1;
			dfs(graph,vis,&k,i);

			ans += k*(N*N - k);
		}
	}
	return ans;
}

void insertpath(vector<int> graph[], int N, int x1, int y1,int x2, int y2){
	int u = (x1-1)*N + y1;
	int v = (x2-1)*N + y2;

	graph[u].push_back(v);
	graph[v].push_back(u);
}

int main() 
{ 
    int N = 2; 
  
    vector<int> graph[N*N + 1]; 
  
    insertpath(graph, N, 1, 1, 1, 2); 
    insertpath(graph, N, 1, 2, 2, 2); 
  
    cout << countNonAccessible(graph, N) << endl; 
    return 0; 
}
//Complexity:O(N*N)