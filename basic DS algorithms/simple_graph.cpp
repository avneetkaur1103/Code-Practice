#include <iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> edges[],int u,int v){
	edges[u].push_back(v);
	edges[v].push_back(u);
}

void printedges(vector<int> edges[], int n){
	vector<int>::iterator it;
	for (int i=0; i<n; i++){
		cout<<i;
		for (it = edges[i].begin();  it !=edges[i].end(); ++it)
			cout <<  "-->" << *it;
		cout<<endl;
	}
}
int main() {
	int n = 6;
	vector<int> edges[n];
	addEdge(edges,0,1);
	addEdge(edges,0,4);
	addEdge(edges,1,2);
	addEdge(edges,1,3);
	addEdge(edges,1,4);
	addEdge(edges,2,3);
	addEdge(edges,3,4);
	printedges(edges,n);
	return 0;
}