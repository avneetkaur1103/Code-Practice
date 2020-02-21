#include <iostream>
using namespace std;


int _parent(int i, int arr[]){
	while(arr[i] != i){
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}



bool areInSame(int i, int j, int arr[]){
	return (_parent(i,arr) == _parent(j,arr));
}

void _union(int i, int j, int arr[], int rank[]){
	int a = _parent(i,arr);
	int b = _parent(j,arr);

	if(rank[a]<rank[b]){
		arr[a] = arr[b];
		rank[b] += rank[a];
	}
	else{
		arr[b] = arr[a];
		rank[a] += rank[b];
	}
}

void query(int type, int i, int j, int arr[], int rank[]){
	if(type == 1){
		if(areInSame(i,j,arr))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	if(type == 2){
		if(!areInSame(i,j,arr))
			_union(i,j,arr,rank);
	}
}

int main(){
	int v = 7;
	int arr[v], rank[v];

	for(int i=0;i<v;i++){
		rank[i] = i;
		arr[i] = 1;
	}

	 int q = 11; 
    query(1, 0, 1, arr, rank); 
    query(2, 0, 1, arr, rank); 
    query(2, 1, 2, arr, rank); 
    query(1, 0, 2, arr, rank); 
    query(2, 0, 2, arr, rank); 
    query(2, 2, 3, arr, rank); 
    query(2, 3, 4, arr, rank); 
    query(1, 0, 5, arr, rank); 
    query(2, 4, 5, arr, rank); 
    query(2, 5, 6, arr, rank); 
    query(1, 2, 6, arr, rank); 
    return 0; 
}

//Complexity: O(n)