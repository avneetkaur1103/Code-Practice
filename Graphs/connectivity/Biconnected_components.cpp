#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct Edge{
	int src, dest;
	Edge(int s, int d){
		src = s;
		dest = d;
	}
};

class Graph{
	int V;
	int E;
	int count;
	list<int> *adj;
	void BCCUtil(int i, int disc[], int low[], int parent[], stack<Edge> *s);
	public:
		Graph(int V);
		void addEdge(int u,int v);
		void BCC();
};

Graph::Graph(int V){
	this->V = V;
	this->E = 0;
	count = 0;
	adj = new list<int>[V];
}

void Graph::addEdge(int u,int v){
	adj[u].push_back(v);
	E++;
}

void Graph::BCCUtil(int i, int disc[], int low[], int parent[], stack<Edge> *s){
	
	static int time = 0;
	int children = 0;
	disc[i] = low[i] = ++time;

	list<int>::iterator it;
	for(it = adj[i].begin();it != adj[i].end(); it++){
		int v = *it;

		if(disc[v] == -1){
			children++;
			parent[v] = i;
			s->push(Edge(i,v));

			BCCUtil(v,disc,low,parent,s);

			low[i] = min(low[i],low[v]);

			if((parent[i] == -1 && children>1) || (parent[i] != -1 && low[v] >= disc[i])){
				//case of AP, print stack back
				while(s->top().src != i || s->top().dest != v){
					cout<<s->top().src<<" -> "<<s->top().dest<<"    ";
					s->pop();
				}
				cout<<s->top().src<<" -> "<<s->top().dest<<"    ";
				s->pop();
				cout<<endl;
				count++;
			}
		}
		else if(v != parent[i]){
			low[i] = min(low[i],disc[v]);
			if(disc[i] < disc[v])
				s->push(Edge(i,v));
		}
	}

	
}

void Graph::BCC(){
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	stack<Edge> *s = new stack<Edge>();

	for(int i=0;i<V;i++){
		parent[i] = -1;
		disc[i] = -1;
		low[i] = -1;
	}

	for(int i=0;i<V;i++){
		if(disc[i] == -1)
			BCCUtil(i,disc,low,parent,s);

		int flag =0;
		while(s->size() > 0){
			flag = 1;
			cout<<s->top().src<<" -> "<<s->top().dest<<"    ";
			s->pop();
		}
		if(flag == 1){
			cout<<endl;
			count++;
		}
	}
	cout<<"Number of BCCs: "<<count<<endl;
}

int main(){
	Graph g(12); 
    g.addEdge(0, 1); 
    g.addEdge(1, 0); 
    g.addEdge(1, 2); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
    g.addEdge(3, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 2); 
    g.addEdge(2, 4); 
    g.addEdge(4, 2); 
    g.addEdge(3, 4); 
    g.addEdge(4, 3); 
    g.addEdge(1, 5); 
    g.addEdge(5, 1); 
    g.addEdge(0, 6); 
    g.addEdge(6, 0); 
    g.addEdge(5, 6); 
    g.addEdge(6, 5); 
    g.addEdge(5, 7); 
    g.addEdge(7, 5); 
    g.addEdge(5, 8); 
    g.addEdge(8, 5); 
    g.addEdge(7, 8); 
    g.addEdge(8, 7); 
    g.addEdge(8, 9); 
    g.addEdge(9, 8); 
    g.addEdge(10, 11); 
    g.addEdge(11, 10); 
    g.BCC(); 
    return 0;
}

//Complexity: O(V+E)