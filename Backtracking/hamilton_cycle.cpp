#include <iostream>
using namespace std;

#define V 5

bool isSafe(int graph[][V], int hamcycle[V], int pos, int v){
	if(graph[hamcycle[pos-1]][v] == 0)
		return false;

	for(int i=0;i<pos;i++){
		if (hamcycle[i] == v)
			return false;
	}
	return true;
}

void printsol(int arr[]){
	for(int i=0;i<V;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<arr[0]<<endl;
}

bool hamiltonCycleUtil(int graph[][V], int hamcycle[V] , int pos){
	if(pos == V){
		if(graph[hamcycle[pos-1]][hamcycle[0]])
			return true;
		else
			return false;
	}

	for(int i=1;i<V;i++){
		if (isSafe(graph,hamcycle,pos,i)){
			hamcycle[pos] = i;

			if(hamiltonCycleUtil(graph,hamcycle,pos+1) == true)
					return true;

			hamcycle[pos] = -1;
		}
	}
	return false;
}

bool hamiltonCycle(int graph[V][V]){
	int hamcycle[V];
	//int *hamcycle = new int[V];
	int i;
	for(i=0;i<V;i++)
		hamcycle[i] = -1;

	hamcycle[0] = 0;

	
	if(hamiltonCycleUtil(graph, hamcycle, 1) == false){	
		cout<<"No solution exists"<<endl;
		return false;
	}

	printsol(hamcycle);
		return true;
}

int main(){
	int graph[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}}; 
    hamiltonCycle(graph);

    int graph2[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}}; 

   hamiltonCycle(graph2);                   
   return 0;
}