#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void SCCUtil(int i, int disc[], int low[], bool inStack[], stack<int> *s);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void SCC();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
}

void Graph::SCCUtil(int i, int disc[], int low[], bool inStack[], stack<int> *s){
	
	static int time =0;
	disc[i] = low[i] = ++time;
	inStack[i] = true;
	s->push(i);

	list<int>::iterator it;
	for(it = adj[i].begin();it != adj[i].end(); it++){
		int v = *it;

		if(disc[v] == -1){
			
			SCCUtil(v,disc,low,inStack,s);

			low[i] = min(low[i],low[v]);
		}
		else if(inStack[v]){
			low[i] = min(low[i],disc[v]);
		}
	}

	int w=0;
	if(low[i] == disc[i]){
		while(s->top() != i){
			w = s->top();
			cout<<w<<" ";
			inStack[w] = false;
			s->pop();
		}
		w = s->top();
		cout<<w<<endl;
		inStack[w] = false;
		s->pop();
	}
}

void Graph::SCC(){
	int *disc = new int[V];
	int *low = new int[V];
	bool *inStack = new bool[V];
	stack<int> *s = new stack<int>();

	for(int i=0;i<V;i++){
		inStack[i] = false;
		disc[i] = -1;
		low[i] = -1;
	}

	for(int i=0;i<V;i++){
		if(disc[i] == -1)
			SCCUtil(i,disc,low,inStack,s);
	}
}

int main(){
	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.SCC();
    return 0;
}

//Complexity: O(V+E)