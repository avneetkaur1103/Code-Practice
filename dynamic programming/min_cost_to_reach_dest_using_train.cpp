#include <iostream>
#include <climits>
using namespace std;
#define N 4

int min_cost_to_reach_dest(int cost[][N]){
	int dist[N];
	int i,j;
	for (i=0;i<N;i++)
		dist[i] = INT_MAX;
		
	dist[0] = 0;
	
	for (i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(dist[j] > dist[i] + cost[i][j])
				dist[j] = dist[i] + cost[i][j];
		}
	}
	return dist[N-1];
}

int main() {
	int cost[N][N] = { {0, 15, 80, 90}, 
                      {INT_MAX, 0, 40, 50}, 
                      {INT_MAX, INT_MAX, 0, 70}, 
                      {INT_MAX, INT_MAX, INT_MAX, 0} 
                    }; 
    cout<<"Minimum cost to reach destination using a train: "<<min_cost_to_reach_dest(cost);
	return 0;
}

//Complexity:O(n^2)