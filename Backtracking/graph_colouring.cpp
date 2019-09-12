#include <iostream>
using namespace std;
#define V 4

bool isSafe(int graph[][V], int c,int color[V],int v){
	for(int i=0;i<V;i++){
		if(color[i] == c && graph[v][i])
			return false;
	}
	return true;
}

void printcolor(int color[V]){
	for(int i=0;i<V;i++)
		cout<<color[i]<<"\t";
	cout<<endl;
}

bool graphColouringUtil(int graph[][V], int m, int color[V], int v){
	if(v==V)
		return true;
	
	for(int i=1;i<=m;i++){
		if(isSafe(graph,i,color,v)){
			color[v] = i;

			if(graphColouringUtil(graph,m,color,v+1) == true)
				return true;

			color[v] = 0;
		}
	}
	return false;	
}

bool graphColouring(int graph[][V], int m){
	int color[V], i;
	for(i=0;i<V;i++)
		color[i] = 0;

	if( graphColouringUtil(graph,m,color,0) == false){
		cout<<"olution does not exist"<<endl;
		return false;
	}
	printcolor(color);
	return true;
}

int main(){
	int graph[V][V]= {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}};

    int m = 3;

  	graphColouring(graph,m);
  	return 0;
}