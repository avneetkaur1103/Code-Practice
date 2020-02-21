#include <iostream>
using namespace std;

#define INF INT_MAX
#define V 4

int shortestPathKLength(int graph[][V], int u, int v, int k){
	if (u==v && k==0)
		return 0;
	if(k==1 && graph[u][v] != INF)
		return graph[u][v];
	if(k<=0)
		return INF;

	int res=INF;

	for(int i=0;i<V;i++){
		if(graph[u][i] != INF && u!=i && v!= i){
			int interm_res = shortestPathKLength(graph,i,v,k-1);
			if(interm_res != INF)
				res = min(res, interm_res+graph[u][i]);
		}
	}
	return res;
}

int main(){
	int graph[V][V] = { {0, 10, 3, 2}, 
                        {INF, 0, INF, 7}, 
                        {INF, INF, 0, 6}, 
                        {INF, INF, INF, 0} 
                      }; 
    int u = 0, v = 3, k = 2;
    cout<<shortestPathKLength(graph,u,v,k);
    return 0;
}

//COmplexity:O(V^k)