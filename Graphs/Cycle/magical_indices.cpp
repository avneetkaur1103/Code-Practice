#include <iostream>
using namespace std;

int magicalIndices(int A[], int n){
	int count = 0;

	int parent[n];
	bool visited[n];

	for(int i=0;i<n;i++){
		parent[i] = -1;
		visited[i] = false;
	}

	for(int i=0;i<n;i++){
		int j = i;

		if(parent[j] == -1){
			while(parent[j] == -1){
				parent[j] = i;
				j = (j+A[j]+1)%n;
			}
		}
		if(parent[j] == i){
			while(!visited[j]){
				visited[j] = true;
				count++;
				j = (j+A[j]+1)%n;
			}
		}
	}
	return count;
}

int main() 
{ 
    int A[] = { 0, 0, 0, 2 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    cout << magicalIndices(A, n); 
    return 0; 
}

//Complexity: O(n)