#include <iostream>
#include <queue>
using namespace std;

int fillHeight(int parent[], int height[], int i, int visited[]){
	if (parent[i] == -1){
		visited[i] = 1;
		return 0;
	}

	if(visited[i])
		return height[i];

	visited[i] = 1;
	
	height[i] = 1 +  fillHeight(parent,height,parent[i],visited);

	return height[i];
}

int findHeight(int parent[], int n){
	int maxh =0;

	int height[n];
	int visited[n];

	
	for(int i=0;i<n;i++){
		height[i] = 0;
		visited[i] = 0;
	}

	for(int i=0;i<n;i++){
		height[i] = fillHeight(parent,height,i,visited);
		if(maxh < height[i])
			maxh = height[i];
	}

	return maxh;
}

int main() 
{
    int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 };
    int n = sizeof(parent)/sizeof(parent[0]); 
    cout << "Height is " << findHeight(parent, n); 
    return 0; 
} 

//Complexity: O(n)