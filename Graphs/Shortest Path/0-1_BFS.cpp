#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define V 9

vector<pair<int, int> > adj[V];

void addEdge(int u,int v, int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void zeroOneBFS(int s){
	vector<int> distance(V,INT_MAX);
	deque<int> q;

	distance[s] = 0;
	q.push_back(s);

	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		//vector<pair<int, int> >::iterator it;
		for(int i=0;i<adj[u].size();i++){
			if(distance[adj[u][i].first] > distance[u] + adj[u][i].second){
				distance[adj[u][i].first] = distance[u] + adj[u][i].second;

				if(adj[u][i].second == 0)
					q.push_front(adj[u][i].first);
				else
					q.push_back(adj[u][i].first);
			}
		}
	}

	cout<<"Distance array: "<<endl;
	for(int i=0;i<V;i++)
		cout<<distance[i]<<" ";
}

int main(){
	addEdge(0, 1, 0); 
    addEdge(0, 7, 1); 
    addEdge(1, 7, 1); 
    addEdge(1, 2, 1); 
    addEdge(2, 3, 0); 
    addEdge(2, 5, 0); 
    addEdge(2, 8, 1); 
    addEdge(3, 4, 1); 
    addEdge(3, 5, 1); 
    addEdge(4, 5, 1); 
    addEdge(5, 6, 1); 
    addEdge(6, 7, 1); 
    addEdge(7, 8, 1); 
    int src = 0;
    zeroOneBFS(src); 
    return 0; 
}

//Complexity: O(V+E)