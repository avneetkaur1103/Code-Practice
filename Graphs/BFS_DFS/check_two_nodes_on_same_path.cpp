#include <iostream>
#include <vector>

using namespace std;
#define MAX 10000

int inTime[MAX];
int outTime[MAX];
bool visited[MAX];

int timer = 0;

void dfs(vector<int> graph[], int v){
	visited[v] = true;
	++timer;
	inTime[v] = timer;

	vector<int>::iterator it;

	for(it = graph[v].begin(); it != graph[v].end(); it++){
		if(!visited[*it])
			dfs(graph,*it);
	}

	++timer;
	outTime[v] = timer;
}

bool ifSamePath(int u, int v){
	if(((inTime[u] < inTime[v]) && (outTime[u] > outTime[v])) || ((inTime[u] > inTime[v]) && (outTime[u] < outTime[v])))
		return true;

	return false;
}

int main(){
	int n = 9;
    vector<int> graph[n+1]; 
    graph[1].push_back(2); 
    graph[1].push_back(3); 
    graph[3].push_back(6); 
    graph[2].push_back(4); 
    graph[2].push_back(5); 
    graph[5].push_back(7); 
    graph[5].push_back(8); 
    graph[5].push_back(9); 

    dfs(graph,1);
    ifSamePath(1,5)?cout<<"Yes":cout<<"No";
    cout<<endl;
    ifSamePath(2,6)?cout<<"Yes":cout<<"No";
    return 0;
}

//Complexity: O(n)
//Query Complexity: O(1)