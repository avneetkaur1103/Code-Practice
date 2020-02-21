#include <iostream>
using namespace std;

#define V 5

void DFS(bool graph[][V], bool marked[], int n, int vertex, int start, int &count){
	marked[vertex] =true;

	if(n==0){
		marked[vertex] = false;
		if(graph[vertex][start]){
			count++;
			return;
		}
		else
			return;
	}

	for(int i=0;i<V;i++){
		if(!marked[i] && graph[vertex][i])
			DFS(graph,marked,n-1,i,start,count);
	}
	marked[vertex] = false;

}

int countCycles(bool graph[][V], int n){
	int count =0;
	bool *marked = new bool[V];
	for(int i=0;i<V;i++)
		marked[i] = false;

	for(int i=0;i<V-(n-1);i++){
		DFS(graph,marked,n-1,i,i,count);
		marked[i] = true;
	}

	return count/2;
}

int main(){
	bool graph[][V] = {{0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}, 
                      {1, 0, 1, 0, 1}, 
                      {0, 1, 0, 1, 0}}; 
    int n = 4; 
    cout << "Total cycles of length " << n << " are "
         << countCycles(graph, n); 
    return 0; 
}