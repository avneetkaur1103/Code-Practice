#include <iostream>
using namespace std;

#define V 4

int countPaths(int g[][V], int src, int dest, int k){
	int count =0;
	if(k==0 && src==dest)
		return 1;
	if(k==1 && g[src][dest] == 1)
		return 1;
	if(k<=0)
		return 0;

	for(int a=0;a<V;a++){
		if(g[src][a] == 1)
			count+=countPaths(g,a,dest,k-1);
	}
	return count;
}

int main(){
	int graph[V][V] = { {0, 1, 1, 1}, 
                        {0, 0, 0, 1}, 
                        {0, 0, 0, 1}, 
                        {0, 0, 0, 0} 
                      }; 
    int u = 0, v = 3, k = 2; 
    cout<<countPaths(graph,u,v,k);
    return 0;
}

//Complexity: O(V^k)
//If thru DP - O(V^3 * k)(better)