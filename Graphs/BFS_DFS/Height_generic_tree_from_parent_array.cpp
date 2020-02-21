#include <iostream>
#include <queue>
#include <map>

using namespace std;

vector<int> adj[1000];

int build_tree(int parent[], int n){
	int root_index;
	for(int i=0;i<n;i++){
		if(parent[i] == -1)
			root_index = i;
		else{
			adj[parent[i]].push_back(i);
			adj[i].push_back(parent[i]);
		}
	}
	return root_index;
}

int BFS(int root){
	map<int, int> visited;
	queue<pair<int, int> > q;
	q.push(make_pair(root,0));
	int max_level=0;

	while(!q.empty()){
		pair<int,int> temp = q.front();
		q.pop();
		visited[temp.first] = 1;
		max_level = max(max_level,temp.second);

		
		for (int j = 0; j < adj[temp.first].size(); j++)
		{
			if(!visited[adj[temp.first][j]])
				q.push(make_pair(adj[temp.first][j],temp.second+1));
			
		}
	}

	return max_level;
}

int main() 
{
    int parent[] = { -1, 0, 1, 2, 3 }; 
  
    int n = sizeof(parent) / sizeof(parent[0]); 
  
    int root_index = build_tree(parent, n); 
    //cout<<root_index<<endl;
  
    int mh = BFS(root_index); 
    cout<<mh;
    return 0; 
} 

//Complexity: O(2n)

