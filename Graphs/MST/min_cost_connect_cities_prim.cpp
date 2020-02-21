#include <iostream>
#include <vector>
using namespace std;

int minKey(int key[], bool isInMST[], int n){
	int min_Key = INT_MAX;
	int minIndex;

	for(int i=0;i<n;i++){
		if(isInMST == false && key[i] < min_Key){
			min_Key = key[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void findcost(int n, int graph[][5]){
	int parent[n];
	bool isInMST[n];
	int key[n];

	for(int i=0;i<n;i++){
		isInMST[i] = false;
		key[i] = INT_MAX;
	}
	key[0] = 0;
	parent[0] = -1;

	for(int i=0;i<n;i++){
		int u = minKey(key,isInMST,n);
		isInMST[u] = true;

		for(int j=0;j<n;j++){
			if(graph[u][j] && isInMST[j] == false && graph[u][j] < key[j]){
				key[j] = graph[u][j];
				parent[j] = u;
			}		
		}
	}

	int cost = 0;
	for(int i=1;i<n;i++){
		cost += graph[parent[i]][i];
	}
	cout<<"Total cost: "<<cost<<endl;
}

int main(){
	int n1 = 5; 
  	int city1[][5] = {{0, 1, 2, 3, 4}, 
                               {1, 0, 5, 0, 7}, 
                               {2, 5, 0, 6, 0}, 
                               {3, 0, 6, 0, 0}, 
                               {4, 7, 0, 0, 0}}; 
  	findcost(n1, city1); 
  	return 0;
}

//Complexity: O(n^2)