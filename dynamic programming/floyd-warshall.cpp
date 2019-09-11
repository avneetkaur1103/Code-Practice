#include <iostream>

using namespace std;
#define V 4
#define INF 99999

void printresult(int mindis[][V]){
	for (int i=0;i<V;i++){
		for (int j=0;j<V;j++){
			if(mindis[i][j] == INF)
				cout<<"INF"<<"    ";
			else
				cout<<mindis[i][j]<<"    ";
		}
		cout<<endl;
	}
}

void floyd_warshall(int graph[][V]){
	int i,j;
	int mindis[V][V];
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			mindis[i][j] = graph[i][j];
		}
	}
	
	for (int k=0;k<V;k++){
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				if(mindis[i][j] > mindis[i][k] + mindis[k][j])
					mindis[i][j] = mindis[i][k] + mindis[k][j];
			}
		}
	}
	
	printresult(mindis);
}



int main() {
	int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };  
    floyd_warshall(graph);
	return 0;
}

//Complexity:O(V^3)