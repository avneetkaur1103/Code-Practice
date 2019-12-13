#include <iostream>
using namespace std;
#define INF 9999
#define V 4

bool negCyclefloydWarshall(int graph[][V]){
	int distance[V][V];

	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			distance[i][j] = graph[i][j];
		}
	}

	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for (int j=0; j<V; j++)
			{
				if(distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}

	for(int i=0;i<V;i++){
		if(distance[i][i] < 0 )
			return true;
	}

	return false;
}

int main(){
	int graph[V][V] = { {0   , 1   , INF , INF}, 
                        {INF , 0   , -1  , INF}, 
                        {INF , INF , 0   ,  -1}, 
                        {-1  , INF , INF ,   0}}; 
      
    if (negCyclefloydWarshall(graph)) 
       cout << "Yes"; 
    else
       cout << "No";  
    return 0; 
}