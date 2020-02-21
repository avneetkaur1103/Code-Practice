#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100];

void addedge(int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
}

void dfs(int node, int n, bool visited[], int min_){
	min_ = min(min_,node);

	visited[node] = true;
	vector<int>::iterator it;

	for(it= g[node].begin(); it != g[node].end(); it++){
		if(!visited[*it])
			dfs(*it,n,visited,min_);
	}
}

int minimumSumConnectedComponents(int a[], int n){
	bool visited[n];
	for(int i=0;i<n;i++)
		visited[i] = false;
	int sum=0;

	for(int i=0;i<n;i++){
		if(!visited[a[i]]){
			int min = a[i];
			dfs(a[i],n, visited,min);
			sum += min;
			//cout<<sum<<endl;
		}
	}
	return sum;
}

int main(){
	int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10}; 
    
    addedge(1, 6); 
    addedge(2, 7); 
    addedge(3, 8); 
    addedge(4, 9); 
    addedge(5, 10); 
      
    int n = sizeof(a) / sizeof(a[0]); 

    cout << minimumSumConnectedComponents(a, n); 
    return 0; 
}