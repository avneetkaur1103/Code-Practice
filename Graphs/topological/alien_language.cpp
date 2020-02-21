#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &s);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void topologicalSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v,bool visited[], stack<int> &s){
	visited[v] = true;

	list<int>::iterator it;
	for(it = adj[v].begin(); it!= adj[v].end();it++){
		if(!visited[*it])
			topologicalSortUtil(*it,visited,s);
	}
	s.push(v);
}

void Graph::topologicalSort(){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}

	stack<int> s;

	for(int i=0;i<V;i++){
		if(!visited[i])
			topologicalSortUtil(i,visited,s);
	}

	while(!s.empty()){
		cout<<(char) (s.top()+'a')<<" ";
		s.pop();
	}
}

int min(int x, int y){
	return((x<y)?x:y);
}

void printOrder(string words[], int n){
	Graph g(n);

	for(int i=0;i<n-1;i++){
		string word1= words[i];
		string word2 = words[i+1];

		for(int j=0;j<min(word1.length(), word2.length());j++){
			if(word1[j] != word2[j]){
				g.addEdge(word1[j] - 'a',word2[j]-'a');
				break;
			}
		}
	}

	g.topologicalSort();
}

int main(){
	string words[] = {"caa", "aaa", "aab"}; 
    printOrder(words, 3); 
    return 0; 
}

//Complexity: O(V+E) (DFS)