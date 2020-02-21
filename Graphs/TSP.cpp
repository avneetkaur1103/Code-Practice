#include <iostream>
#include <vector>
using namespace std;

#define V 4

int travllingSalesmanProblem(int graph[][V], int s){
	int res = INT_MAX;
	vector<int> vertex;
	for(int i=0;i<V;i++){
		if (i != s)
		{
			vertex.push_back(i);
		}
	}

	int i;
	do{

		int min_path_wt = 0;
		int k = s;
		for(i=0;i<vertex.size();i++){
			min_path_wt += graph[k][vertex[i]];
			k = vertex[i];
		}
		min_path_wt += graph[k][s];
		res = min(min_path_wt,res);
	}while(next_permutation(vertex.begin(), vertex.end()));

	return res;
}

int main(){
	int graph[][V] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
    int s = 0; 
    cout << travllingSalesmanProblem(graph, s) << endl; 
    return 0; 

}