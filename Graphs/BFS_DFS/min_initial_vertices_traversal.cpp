#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

void dfs(int n, int m, int adj[][MAX], bool vis[][MAX], int N, int M){
	vis[n][m] = 1;

	if(n+1<N && !vis[n+1][m] && adj[n][m] >= adj[n+1][m])
		dfs(n+1,m,adj,vis,N,M);

	if(n-1>=0 && !vis[n-1][m] && adj[n][m] >= adj[n-1][m])
		dfs(n-1,m,adj,vis,N,M);

	if(m+1<M && !vis[n][m+1] && adj[n][m] >= adj[n][m+1])
		dfs(n,m+1,adj,vis,N,M);

	if(m-1>=0 && !vis[n][m-1] && adj[n][m] >= adj[n][m-1])
		dfs(n,m-1,adj,vis,N,M);
}

void printMinSources(int adj[][MAX], int N, int M){
	vector<pair<long int,pair<int, int> > > x;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			x.push_back(make_pair(adj[i][j], make_pair(i,j)));
		}
	}

	sort(x.begin(), x.end());

	bool vis[N][MAX];
	memset(vis,false,sizeof(vis));

	for(int i=x.size() - 1; i>=0; i--){
		if(!vis[x[i].second.first][x[i].second.second]){
			cout<<"("<<x[i].second.first<<", "<<x[i].second.second<<")"<<endl;
			dfs(x[i].second.first, x[i].second.second,adj,vis,N,M);
		}
	}


}

int main(){
	int N = 2, M = 2; 
  
    int adj[2][MAX] = {{3, 3}, 
                       {1, 1}}; 
    printMinSources(adj, N, M); 
    return 0; 
}
