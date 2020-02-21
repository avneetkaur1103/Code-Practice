#include <iostream>
#include <queue>
using namespace std;

void fillDepth(int parent[], int depth[], int i){
	if (depth[i] != 0)
		return;

	if (parent[i] == -1){
		depth[i] = 1;
		return;
	}

	if(depth[parent[i]] == 0)
		fillDepth(parent,depth,parent[i]);

	depth[i] =  depth[parent[i]] + 1;
}

int findHeight(int parent[], int n){
	int depth[n];
	
	for(int i=0;i<n;i++)
		depth[i] = 0;

	for(int i=0;i<n;i++)
		fillDepth(parent,depth,i);

	int height = depth[0];
	for(int i=1;i<n;i++){
		if(height < depth[i])
			height = depth[i];
	}

	return height;
}

int main() 
{
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof(parent)/sizeof(parent[0]); 
    cout << "Height is " << findHeight(parent, n); 
    return 0; 
} 

//Complexity: O(n)