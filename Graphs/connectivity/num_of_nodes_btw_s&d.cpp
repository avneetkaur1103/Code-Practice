#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int totalNodes(vector<int> adjac[], int n, int s, int d){
	bool visited[n];
	int parent[n];

	for(int i=0;i<n;i++){
		visited[i] = false;
		parent[i] = -1;
	}

	visited[s] = true;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int m = q.front();
		q.pop();

		vector<int>::iterator it;
		for(it = adjac[m].begin();it != adjac[m].end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
				parent[*it] = m;
			}
		}
	}

	int count = 0;
	int i= parent[d];
	while(i != s){
		count++;
		i = parent[i];
	}
	return count;
}

int main(){

	vector<int> adjac[7];
	adjac[1].push_back(4); 
    adjac[4].push_back(1); 
    adjac[5].push_back(4); 
    adjac[4].push_back(5); 
    adjac[4].push_back(2); 
    adjac[2].push_back(4); 
    adjac[2].push_back(6); 
    adjac[6].push_back(2); 
    adjac[6].push_back(3); 
    adjac[3].push_back(6); 
  
    cout << totalNodes(adjac, 7, 1, 3); 
  
    return 0; 
}

//Complexity: O(n)