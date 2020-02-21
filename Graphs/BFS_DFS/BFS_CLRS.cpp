#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void addEdge(vector<int>g[], int s, int d){
	g[s].push_back(d);
	g[d].push_back(s);
}

vector<int> d;
vector<int> p;
vector<string> color;

void BFS(vector<int> g[], int v){
	queue<int> q;
	q.push(v);

	color[v] = "green";
	d[v] = 0;

	vector<int>::iterator it;
	while(!q.empty()){
		int temp = q.front();
		q.pop();

		cout<<temp<<" ";

		for( it = g[temp].begin();it != g[temp].end(); it++){
			if(color[*it] == "white"){
				color[*it] = "green";
				d[*it] = d[temp] + 1;
				p[*it] = temp;
				q.push(*it);
			}
		}
		color[temp] = "dark-green";
	}

}

void BFSFull(vector<int> g[], int v){
	d.assign(v,0);
	p.assign(v,-1);
	color.assign(v,"white");

	for(int i=0;i<v;i++){
		if(color[i] == "white")
			BFS(g,i);
	}
}

int main(){
	int v = 7;
	vector<int> g[v];
	addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 1, 4); 
    addEdge(g, 2, 5); 
    addEdge(g, 2, 6); 
  
    BFSFull(g, v); 
  
    return 0;
}

//Complexity: O(V+E)