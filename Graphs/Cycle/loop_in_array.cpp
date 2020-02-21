#include <iostream>
#include <vector>
using namespace std;

bool isCycleUtil(int v, bool visited[], bool recur[], vector<int> adj[]){
	visited[v] = true;
	recur[v] = true;

	for(int i=0;i<adj[v].size(); i++){
		if(!visited[adj[v][i]] && isCycleUtil(adj[v][i],visited,recur,adj))
			return true;
		else if(visited[adj[v][i]] && recur[adj[v][i]])
			return true;
	}
	recur[v] = false;;
	return false;
}

bool isCycle(int arr[],int n){
	bool visited[n];
	bool recur[n];

	for(int i=0;i<n;i++){
		visited[i] = false;
		recur[i] = false;
	}

	vector<int> adj[n];
	for(int i=0;i<n;i++){
		if(i != (i+arr[i]+n)%n)
			adj[i].push_back((arr[i]+i+n)%n);
	}

	for(int i=0;i<n;i++){
		if(!visited[i])
			if(isCycleUtil(i,visited,recur,adj))
				return true;
	}
	return false;
}


int main() 
{ 
    int arr[] = {2, -1, 1, 2, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    if (isCycle(arr, n)) 
        cout << "Yes"<<endl; 
    else
        cout << "No"<<endl; 
    return 0; 
} 