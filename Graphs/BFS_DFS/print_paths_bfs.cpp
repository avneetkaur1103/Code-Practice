#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printPath(vector<int> path){
	int size = path.size();

	for(int i=0;i<size;i++)
		cout<<path[i]<<" ";
}

bool notVisited(vector<int> path, int i){
	int size = path.size();

	for(int j=0;j<size;j++){
		if(path[j] == i)
			return false;
	}
	return true;
}

void findpaths(vector<vector<int> > g, int s, int d, int v){
	queue<vector<int> > q;
	vector<int> path;

	path.push_back(s);
	q.push(path);

	while(!q.empty()){
		path = q.front();
		q.pop();

		int l = path[path.size() - 1];

		if(l == d){
			printPath(path);
			cout<<endl;
		}
		else{
			for(int i =0;i<g[l].size();i++){
				if(notVisited(path,g[l][i])){
					vector<int> new_path(path);
					new_path.push_back(g[l][i]);
					q.push(new_path);
				}
			}
		}
	}
}

int main() 
{ 
    vector<vector<int> > g;
    int v = 4; 
    g.resize(4);

    g[0].push_back(3); 
    g[0].push_back(1); 
    g[0].push_back(2); 
    g[1].push_back(3); 
    g[2].push_back(0); 
    g[2].push_back(1); 
  
    int src = 2, dst = 3;
    findpaths(g, src, dst, v); 
  
    return 0;
}

//Complexity: O(V+E)