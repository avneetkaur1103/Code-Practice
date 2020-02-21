#include <iostream>
using namespace std;

void build_tree(int prufer[], int n){
	int v = n+2;
	int vertex[v];

	for(int i=0;i<v;i++)
		vertex[i] = 0;

	for(int i=0;i<n;i++){
		vertex[prufer[i] -1] += 1;
	}

	for(int i=0; i<n; i++){
		for(int j=0;j<v;j++){
			if(vertex[j] == 0){
				vertex[j] = -1;
				cout<<"("<<(j+1)<<", "<<prufer[i]<<")  ";
				vertex[prufer[i] -1]--;
				break;
			}
		}
	}

	int j=0;

	for(int i=0;i<v;i++){
		if(vertex[i] ==0 && j==0){
			cout<<"("<<(i+1)<<", ";
			j++;
		}
		else if(vertex[i] ==0 && j==1){
			cout<<(i+1)<<") ";
		}
	}
}

int main(){
	int prufer[] = { 4, 1, 3, 4 };
	int n = sizeof(prufer)/sizeof(prufer[0]);
	build_tree(prufer,n);
	return 0;
}